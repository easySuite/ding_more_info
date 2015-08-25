<?php
/**
 * @file
 * API definitions.
 */

/**
 * Implements hook_more_info_support().
 */
function hook_more_info_support() {
  return array(
    'module_name' => array(
      'display' => 'dummy',
      'label' => 'Label',
      'weight' => '99',
    ),
  );
}
