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
    'display' => array(
      'collection_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'collection_primary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'compact' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'ding_item_viewer_big' => array(
        'label' => 'hidden',
        'module' => 'ding_more_info',
        'settings' => array(),
        'type' => 'ting_more_info_default',
        'weight' => 7,
      ),
      'ding_item_viewer_small' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
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
      'ting_search_carousel' => array(
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
      'weight' => 39,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('More info');

  return $field_instances;
}
