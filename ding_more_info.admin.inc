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
