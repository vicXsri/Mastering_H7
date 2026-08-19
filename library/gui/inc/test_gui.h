/*
 * test_gui.h
 *
 *  Created on: Aug 19, 2026
 *      Author: Srivisweswara Mohan Santhi
 */

#ifndef GUI_INC_TEST_GUI_H_
#define GUI_INC_TEST_GUI_H_

#include "main.h"

void my_flush_cb(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map);

void lvgl_init(void);
void lvgl_helloWorld(void);
void lvgl_start(void);

void lvgl_battery_gui(void);
void lvgl_battery_ui_update(float voltage, float soc);


void set_color(uint64_t start, uint64_t stop, uint8_t r, uint8_t g, uint8_t b);
void VIBGYOR_fb(void);


#endif /* GUI_INC_TEST_GUI_H_ */
