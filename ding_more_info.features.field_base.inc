<?php
/**
 * @file
 * ding_more_info.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ding_more_info_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'ting_more_info'
  $field_bases['ting_more_info'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'ting_more_info',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'ding_more_info',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'ting_more_info',
  );

  return $field_bases;
}
