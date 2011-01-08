<?php
// $Id$

/**
 * @file
 *   administration page callbacks for paccess module
 */

/**
 * Form builder. admin/settings/paccess
 *
 * @ingroup forms
 * @see system_settings_form().
 */
function paccess_admin_settings() { 
  $features = features_get_features();
  // Organize feature sets.
  foreach($features as $feature) {
    $featureset = ($feature->info['package']) ? $feature->info['package'] : 'Other';
  }

  return system_settings_form($form);
} 
