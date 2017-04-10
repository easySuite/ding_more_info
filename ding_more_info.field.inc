<?php

/**
 * @file
 * Field hook implementations.
 */

/**
 * Implements hook_field_info().
 */
function ding_more_info_field_info() {
  return array(
    'ting_more_info' => array(
      'label' => t('Ting more info'),
      'description' => t('Ting more info'),
      'default_widget' => 'hidden',
      'default_formatter' => 'ting_more_info_default',
      'virtual_field' => array(
        'entity_types' => array('ting_object'),
        'add_widget' => TRUE,
      ),
    ),
  );
}

/**
 * Implements hook_field_formatter_info().
 */
function ding_more_info_field_formatter_info() {
  return array(
    'ting_more_info_default' => array(
      'label' => t('Default'),
      'field types' => array(
        'ting_more_info',
      ),
      'settings' => array(),
    ),
  );
}

/**
 * Implements hook_field_load().
 */
function ding_more_info_field_load($entity_type, $entities, $field, $instances, $langcode, &$items, $age) {
  if ($field['type'] == 'ting_more_info') {
    foreach ($entities as $id => $entity) {
      $items[$id][0] = array(
        'id' => $entity->id,
      );
    }
  }
}

/**
 * Implements hook_field_formatter_view().
 */
function ding_more_info_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  foreach ($items as $delta => $item) {
    switch ($display['type']) {
      case 'ting_more_info_default':
        $collection = ting_collection_load($entity->id);
        $prefix = count($collection->types) > 1 && arg(0) == 'search' ? 'collection' : 'object';

        $type = 'ting_object';
        $element[$delta] = array(
          '#prefix' => '<div class="more-info-wrapper">',
          '#markup' => l(t('More info'), "ting/$prefix/" . $entity->ding_entity_id, array()),
          '#suffix' => '</div>',
        );

      break;
    }
  }

  return $element;
}
