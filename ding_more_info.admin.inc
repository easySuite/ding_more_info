<?php
/**
 * @file
 * Adminisration interface logic.
 */

/**
 * More info settings form definition.
 */
function ding_more_info_admin_form($form, $form_state) {
  $entity_info = entity_get_info('ting_object');

  $options = array_map(function ($view_mode) {
    return $view_mode['label'];
  }, $entity_info['view modes']);

  if (!empty($options)) {
    $form['implementations'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Enable more info button on:'),
      '#options' => $options,
      '#default_value' => variable_get('more_info_default_implementations', array()),
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save settings'),
    );
  }
  else {
    $form['empty'] = array(
      '#type' => 'item',
      '#markup' => t('No module implements more info button.'),
    );
  }

  return $form;
}

/**
 * Custom submit handler for the more info admin form.
 *
 * @see ding_more_info_admin_form()
 */
function ding_more_info_admin_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $implementations = $values['implementations'];

  variable_set('more_info_default_implementations', array_filter($implementations));

  ding_more_info_setup_instances($implementations);
}

/**
 * Create/remove more info field instances.
 *
 * @param array $implementations
 *   An array of modules that require field modifications.
 */
function ding_more_info_setup_instances(array $implementations) {
  $field_name = 'ting_more_info';
  $field_info = field_info_field($field_name);
  if (empty($field_info)) {
    $field = array(
      'field_name' => $field_name,
      'type' => 'ting_more_info'
    );
    field_create_field($field);
  }

  foreach ($implementations as $implementation => $v) {
    $field_instance = field_info_instance('ting_object', $field_name, 'ting_object');
    if (!empty($field_info) && empty($field_instance)) {
      $instance = array(
        'field_name' => $field_name,
        'entity_type' => 'ting_object',
        'bundle' => 'ting_object',
        'label' => 'Ting More info',
        'display' => array(
          $implementation =>  array(
            'label' => 'hidden',
            'weight' => 19,
            'settings' => array(),
            'module' => 'ding_more_info',
            'type' => 'ting_more_info_default',
          ),
        ),
      );
      field_create_instance($instance);
    }
    elseif (!empty($field_instance)) {
      if ($v) {
        $field_instance['display'][$implementation]['type'] = 'ting_more_info_default';
        // Hide label from the display.
        $field_instance['display'][$implementation]['label'] = 'hidden';

        // Move field to the group info.
        $groups = field_group_read_groups(array(
          'entity_type' => 'ting_object',
          'bundle'      => 'ting_object',
          'mode'   => $implementation
        ));
        $group = $groups['ting_object']['ting_object'][$implementation]['group_info'];
        if (!in_array($field_name, $group->children)) {
          array_unshift($group->children, $field_name);
        }
        field_group_group_save($group);
      }
      else {
        $field_instance['display'][$implementation]['type'] = 'hidden';
      }
      // Hide moreinfo link on the main display.
      $field_instance['display']['default']['type'] = 'hidden';

      // Update field instance.
      field_update_instance($field_instance);
    }
  }
}
