/*
 * test_gui.c
 *
 *  Created on: Aug 19, 2026
 *      Author: Srivisweswara Mohan Santhi
 */

#include "test_gui.h"

#define fb_size	480 * 272 * 3

lv_display_t * disp;
static lv_obj_t *box1;
static lv_obj_t *box2;
static lv_obj_t *label1;
static lv_obj_t *label2;

extern uint8_t layer0_fb[fb_size];

void my_flush_cb(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map){
    lv_display_flush_ready(disp);
}

void lvgl_init(void){

	/* Init the lvgl */
    lv_init();

	/* Create a display */
    disp = lv_display_create(480, 272);

	/* Set color format */
    lv_display_set_color_format(disp, LV_COLOR_FORMAT_RGB888);

    /* Set the flush */
    lv_display_set_flush_cb(disp, my_flush_cb);

    /* Set the layer buffers */
    lv_display_set_buffers(disp, layer0_fb, NULL, sizeof(layer0_fb), LV_DISPLAY_RENDER_MODE_DIRECT);

    /* turn on the fps and cpu performance viewer */
    lv_sysmon_show_performance(NULL);
    lv_sysmon_show_memory(NULL);
}

void lvgl_helloWorld(void){
	    lv_obj_t * label = lv_label_create(lv_screen_active());
	    lv_label_set_text(label, "Hello Worldd !!!!!");
	    lv_obj_center(label);
}

void lvgl_battery_gui(void){

	box1 = lv_obj_create(lv_screen_active());
	lv_obj_set_size(box1, 180, 80);
	lv_obj_align(box1, LV_ALIGN_CENTER, -110, 0);

	box2 = lv_obj_create(lv_screen_active());
	lv_obj_set_size(box2, 180, 80);
	lv_obj_align(box2, LV_ALIGN_CENTER, 110, 0);

	label1 = lv_label_create(box1);
	lv_obj_center(label1);

	label2 = lv_label_create(box2);
	lv_obj_center(label2);

}

void lvgl_battery_ui_update(float voltage, float soc){
    static char buf1[32];
    static char buf2[32];

    snprintf(buf1, sizeof(buf1), "Voltage\n%.3f V", voltage);
    snprintf(buf2, sizeof(buf2), "SOC\n%.2f %%", soc);

    lv_label_set_text(label1, buf1);
    lv_label_set_text(label2, buf2);
}

void lvgl_start(void){

	/* Init the lvgl */
	lvgl_init();

	/* write the graphics and animations / App */
//	lvgl_helloWorld();
	lvgl_battery_gui();
	/* Start the lvgl gui in a while loop ! */
	while(1){
		lv_timer_handler();
		lvgl_battery_ui_update(MAX17048_Get_Voltage(), MAX17048_Get_SOC());
		delay(3);
	}
}


void set_color(uint64_t start, uint64_t stop, uint8_t r, uint8_t g, uint8_t b){

	for (uint32_t i = start; i <= stop; i += 3) {
	    layer0_fb[i + 0] = b; // R
	    layer0_fb[i + 1] = g; // B
	    layer0_fb[i + 2] = r; // G
	}

}

void VIBGYOR_fb(void){
    /* Violet : rows   0 -  38 */
    set_color(0,      56157, 148,   0, 211);

    /* Indigo : rows  39 -  77 */
    set_color(56160, 112317,  75,   0, 130);

    /* Blue   : rows  78 - 116 */
    set_color(112320, 168477,   0,   0, 255);

    /* Green  : rows 117 - 155 */
    set_color(168480, 224637,   0, 255,   0);

    /* Yellow : rows 156 - 194 */
    set_color(224640, 280797, 255, 255,   0);

    /* Orange : rows 195 - 233 */
    set_color(280800, 336957, 255, 127,   0);

    /* Red    : rows 234 - 271 */
    set_color(336960, 391677, 255,   0,   0);
}
