idf_component_register(SRCS "src/factory_reset_task.c"
                       INCLUDE_DIRS "include"
                       REQUIRES nvs_flash app_update driver
)