<?php
/**
 * @file
 * Advanced Poll Media administration options
 */

/*
 * Implements hook_form()
*/

function advpoll_media_settings_form($form, &$form_state) {
  $form = array();
  $form['advpoll_media_choice_style_image'] = array(
    '#type' => 'select',
    '#title' => t('Style') ,
    '#default_value' => variable_get('advpoll_media_choice_style_image', 'thumbnail') ,
    '#options' => image_style_options(FALSE, PASS_THROUGH) ,
    '#description' => t("The poll's thumbnail size") ,
  );
  $form['advpoll_media_choice_samesize'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('advpoll_media_choice_samesize', FALSE) ,
    '#title' => t('All media should have the same size') ,
    '#description' => t("All the media appear in same size") ,
  );
  $form['advpoll_media_choice_video_player'] = array(
    '#type' => 'select',
    '#title' => t('Should Video show a player ?') ,
    '#default_value' => variable_get('advpoll_media_choice_video_player', 1) ,
    '#options' => array(
      1 => t('Yes') ,
      0 => t('No')
    ) ,
    '#description' => t("The video poll behaviour") ,
  );
  $form['advpoll_media_choice_video_player_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Video player width') ,
    '#default_value' => variable_get('advpoll_media_choice_video_player_width', 480) ,
    '#size' => 4,
    '#states' => array(
      'visible' => array(
        ':input[name="advpoll_media_choice_video_player"]' => array(
          'value' => 1
        ) ,
        ':input[name="advpoll_media_choice_samesize"]' => array(
          'checked' => FALSE
        ) ,
      ) ,
    ) ,
  );
  $form['advpoll_media_choice_video_player_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Video player height') ,
    '#default_value' => variable_get('advpoll_media_choice_video_player_height', 480) ,
    '#size' => 4,
    '#states' => array(
      'visible' => array(
        ':input[name="advpoll_media_choice_video_player"]' => array(
          'value' => 1
        ) ,
        ':input[name="advpoll_media_choice_samesize"]' => array(
          'checked' => FALSE
        ) ,
      ) ,
    ) ,
  );
  $form['advpoll_media_choice_video_player_autoplay'] = array(
    '#type' => 'select',
    '#title' => t('Video player autoplay') ,
    '#default_value' => variable_get('advpoll_media_choice_video_player_autoplay', FALSE) ,
    '#options' => array(
      FALSE => t('No') ,
      TRUE => t('Yes')
    ) ,
    '#states' => array(
      'visible' => array(
        ':input[name="advpoll_media_choice_video_player"]' => array(
          'value' => 1
        ) ,
      ) ,
      '#description' => t("The video poll behaviour") ,
    ) ,
  );
  $form['advpoll_media_choice_sound_player_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Sound player width') ,
    '#default_value' => variable_get('advpoll_media_choice_sound_player_width', 300) ,
    '#size' => 4,
  );
  $form['advpoll_media_choice_sound_player_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Sound player height') ,
    '#default_value' => variable_get('advpoll_media_choice_sound_player_height', 220) ,
    '#size' => 4,
  );
  return system_settings_form($form);
}
