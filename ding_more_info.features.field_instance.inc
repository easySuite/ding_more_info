<?php
/**
 * @file
 * ding_more_info.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ding_more_info_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'ting_object-ting_object-ting_more_info'
  $field_instances['ting_object-ting_object-ting_more_info'] = array(
    'bundle' => 'ting_object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'ding_entity',
    'display' => array(
      'collection_list' => array(
        'label' => 'hidden',
        'module' => 'ding_more_info',
        'settings' => array(),
        'type' => 'ting_more_info_default',
        'weight' => 8,
      ),
      'collection_primary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'objects_in_popup' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'ding_more_info',
        'settings' => array(),
        'type' => 'ting_more_info_default',
        'weight' => 20,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'ting_reference_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'user_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'ting_object',
    'field_name' => 'ting_more_info',
    'label' => 'More info',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'virtual_field',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 42,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('More info');

  return $field_instances;
}
