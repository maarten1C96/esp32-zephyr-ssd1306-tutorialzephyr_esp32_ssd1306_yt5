// #include <stdint.h>
#include <stdio.h>
#include <zephyr/device.h>
#include <zephyr/kernel.h>
// #include <zephyr/drivers/display_i2c.h>
#include <zephyr/display_i2c/cfb.h>
#include <zephyr/logging/log.h>

// #include "logo_image.h"

#define DISPLAY_BUFFER_PITCH 128

LOG_MODULE_REGISTER(display_i2c);

static const struct device *display_i2c = DEVICE_DT_GET(DT_NODELABEL(ssd1306));

void main(void)
{
  if (display_i2c == NULL) {
    LOG_ERR("device pointer is NULL");
    return;
  }

  if (!device_is_ready(display_i2c)) {
    LOG_ERR("display_i2c device is not ready");
    return;
  }

  int ret;
  ret = cfb_framebuffer_init(display_i2c);
  if (ret != 0)
  {
    LOG_ERR("Could not initialise display_i2c");
    return;
  }

  char display_buffer[128];
  ret = cfb_print(display_i2c, "compiled at:", 0, 0);
  snprintf(display_buffer, sizeof(display_buffer), "%s", COMPILE_DATE);
  ret = cfb_print(display_i2c, display_buffer, 0, 20);
  snprintf(display_buffer, sizeof(display_buffer), "%s", COMPILE_TIME);
  ret = cfb_print(display_i2c, display_buffer, 0, 40);
  if (ret != 0)
  {
    LOG_ERR("Could not print to display_i2c");
    return;
  }
  
  ret = cfb_framebuffer_finalize(display_i2c);
  if (ret != 0)
  {
    LOG_ERR("Could not finalise to display_i2c");
    return;
  }

  // struct display_capabilities capabilities;
  // display_get_capabilities(display_i2c, &capabilities);

  // const uint16_t x_res = capabilities.x_resolution;
  // const uint16_t y_res = capabilities.y_resolution;

  // LOG_INF("x_resolution: %d", x_res);
  // LOG_INF("y_resolution: %d", y_res);
  // LOG_INF("supported pixel formats: %d", capabilities.supported_pixel_formats);
  // LOG_INF("screen_info: %d", capabilities.screen_info);
  // LOG_INF("current_pixel_format: %d", capabilities.current_pixel_format);
  // LOG_INF("current_orientation: %d", capabilities.current_orientation);
	 
  // const struct display_buffer_descriptor buf_desc = {
  //   .width = x_res,
  //   .height = y_res,
  //   .buf_size = x_res * y_res,
  //   .pitch = DISPLAY_BUFFER_PITCH
  // };

  // if (display_write(display_i2c, 0, 0, &buf_desc, buf) != 0) {
  //   LOG_ERR("could not write to display_i2c");
  // }

  // if (display_set_contrast(display_i2c, 0) != 0) {
  //   LOG_ERR("could not set display_i2c contrast");
  // }
  // size_t ms_sleep = 5;

  // while (true) {
  //   // Increase brightness
  //   for (size_t i = 0; i < 255; i++) {
  //     display_set_contrast(display_i2c, i);
  //     k_sleep(K_MSEC(ms_sleep));
  //   }
  // while (true) {
  //   // Increase brightness
  //   for (size_t i = 0; i < 255; i++) {
  //     display_set_contrast(display_i2c, i);
  //     k_sleep(K_MSEC(ms_sleep));
  //   }

  //   // Decrease brightness
  //   for (size_t i = 255; i > 0; i--) {
  //     display_set_contrast(display_i2c, i);
  //     k_sleep(K_MSEC(ms_sleep));
  //   }
  // }
  //   // Decrease brightness
  //   for (size_t i = 255; i > 0; i--) {
  //     display_set_contrast(display_i2c, i);
  //     k_sleep(K_MSEC(ms_sleep));
  //   }
  // }
}
