<?php
$aliases['dev'] = array(
  'root' => '/home/forge/<PROJECT>.untold.work/public',
  'uri' => '<PROJECT>.untold.work',
  'remote-host' => '54.67.43.192',
  'remote-user' => 'forge',
  'path-aliases' => array(
    '%drush-script' => '/usr/local/bin/drush',
    '%files' => 'sites/default/files',
  )
);
$aliases['local'] = array(
  'root' => '/Users/<USER>/Sites/<PROJECT>/public',
  'uri' => '<PROJECT>.untold.dev',
  'path-aliases' => array(
    '%drush-script' => 'drush',
      '%files' => 'sites/default/files',
  )
);