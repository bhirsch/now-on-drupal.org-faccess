<?php
// $Id$

/**
 * @file
 *   administration page callbacks for extra module
 */

/**
 * Form builder. admin/settings/extra
 *
 * @ingroup forms
 * @see system_settings_form().
 */
function extra_admin_settings() { 
  $modules = features_get_modules();
 
  $form['extra'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Extras'),
    '#default_value' => variable_get('extra', FALSE),
    '#description' => t('Checked modules will be hidden '
      .'from all users except User 1 on !features.', 
      array('!features' => l('admin/build/features', 'admin/build/features'))),
  ); 
  foreach($modules as $module) {
    $form['extra']['#options'][$module->name] = $module->info['name'];  
  }

  return system_settings_form($form);
} 
