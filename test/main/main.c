/**
 * @brief ESP32_factory_reset_task - Demonstrates the use of "factory_reset_task"
 *
 * Erases WiFi credentials in nvram when GPIO#0 pulled low.
 *
 * Inspired by <https://github.com/espressif/esp-idf/blob/master/examples/system/ota/native_ota_example/main/native_ota_example.c>
 * 
 * Written in 2019 by Coert Vonk 
 * 
 * To the extent possible under law, the author(s) have dedicated all copyright and related and
 * neighboring rights to this software to the public domain worldwide. This software is
 * distributed without any warranty. You should have received a copy of the CC0 Public Domain
 * Dedication along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
 * 
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdlib.h>
#include <string.h>
#include <nvs_flash.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <factory_reset_task.h>

void
app_main()
{
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    xTaskCreate(&factory_reset_task, "factory_reset_task", 4096, NULL, 5, NULL);
}