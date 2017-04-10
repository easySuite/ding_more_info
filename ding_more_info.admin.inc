<?php
/**
 * @file
 * Adminisration interface logic.
 */

/**
 * More info settings form definition.
 */
function ding_more_info_admin_form($form, $form_state) {
  $modules = module_invoke_all('more_info_support');
  $options = array();

  foreach ($modules as $k => $v) {
    if (module_exists($k)) {
      $options[] = $k;
    }
  }

  if (!empty($options)) {
    $options = array_combine($options, $options);

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
function ding_more_info_setup_instances(array $modules) {
  $hooks = module_invoke_all('more_info_support');

  $field_name = 'ting_more_info';
  $field_info = field_info_field($field_name);
  if (empty($field_info)) {
    $field = array(
      'field_name' => $field_name,
      'type' => 'ting_more_info'
    );
    field_create_field($field);
  }

  foreach ($modules as $module => $v) {
    if (isset($hooks[$module])) {
      $field_instance = field_info_instance('ting_object', $field_name, 'ting_object');
      if (!empty($field_info) && empty($field_instance)) {
        $instance = array(
          'field_name' => $field_name,
          'entity_type' => 'ting_object',
          'bundle' => 'ting_object',
          'label' => 'Ting More info',
          'display' => array(
            $hooks[$module]['display'] =>  array(
              'label' => $hooks[$module]['label'],
              'weight' => $hooks[$module]['weight'],
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
          $field_instance['display'][$hooks[$module]['display']]['type'] = 'ting_more_info_default';
        }
        else {
          $field_instance['display'][$hooks[$module]['display']]['type'] = 'hidden';
        }
        field_update_instance($field_instance);
      }
    }
  }
}
