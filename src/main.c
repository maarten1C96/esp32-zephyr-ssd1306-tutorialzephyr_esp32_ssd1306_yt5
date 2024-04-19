// #include <stdint.h>
#include <stdio.h>
#include <zephyr/device.h>
#include <zephyr/kernel.h>
// #include <zephyr/drivers/display.h>
#include <zephyr/display/cfb.h>
#include <zephyr/logging/log.h>

// #include "logo_image.h"

#define DISPLAY_BUFFER_PITCH 128

LOG_MODULE_REGISTER(display_1);

static const struct device *display_1 = DEVICE_DT_GET(DT_NODELABEL(ssd1306));

void main(void)
{
  if (display_1 == NULL) {
    LOG_ERR("device pointer is NULL");
    return;
  }

  if (!device_is_ready(display_1)) {
    LOG_ERR("display_1 device is not ready");
    return;
  }

  int ret;
  ret = cfb_framebuffer_init(display_1);
  if (ret != 0)
  {
    LOG_ERR("Could not initialise display_1");
    return;
  }

  char display_buffer[128];
  ret = cfb_print(display_1, "compiled at:", 0, 0);
  snprintf(display_buffer, sizeof(display_buffer), "%s", COMPILE_DATE);
  ret = cfb_print(display_1, display_buffer, 0, 20);
  snprintf(display_buffer, sizeof(display_buffer), "%s", COMPILE_TIME);
  ret = cfb_print(display_1, display_buffer, 0, 40);
  if (ret != 0)
  {
    LOG_ERR("Could not print to display_1");
    return;
  }
  
  ret = cfb_framebuffer_finalize(display_1);
  if (ret != 0)
  {
    LOG_ERR("Could not finalise to display_1");
    return;
  }
