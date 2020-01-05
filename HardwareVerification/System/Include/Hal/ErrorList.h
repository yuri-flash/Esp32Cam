#include "esp_err.h"
#include "esp_wifi.h"

#define ErrorCodeAndName(err)    {err, #err}

typedef struct {
    int code;
    const char *msg;
} errorMessage;

static const errorMessage ErrorMessageTable[] = {
    // components/esp_common/include/esp_err.h
#   ifdef      ESP_FAIL
    ErrorCodeAndName(ESP_FAIL),                                       /*    -1 Generic esp_err_t code indicating failure */
#   endif
#   ifdef      ESP_OK
    ErrorCodeAndName(ESP_OK),                                         /*     0 esp_err_t value indicating success (no error) */
#   endif
#   ifdef      ESP_ERR_NO_MEM
    ErrorCodeAndName(ESP_ERR_NO_MEM),                                 /*   257 0x101 Out of memory */
#   endif
#   ifdef      ESP_ERR_INVALID_ARG
    ErrorCodeAndName(ESP_ERR_INVALID_ARG),                            /*   258 0x102 Invalid argument */
#   endif
#   ifdef      ESP_ERR_INVALID_STATE
    ErrorCodeAndName(ESP_ERR_INVALID_STATE),                          /*   259 0x103 Invalid state */
#   endif
#   ifdef      ESP_ERR_INVALID_SIZE
    ErrorCodeAndName(ESP_ERR_INVALID_SIZE),                           /*   260 0x104 Invalid size */
#   endif
#   ifdef      ESP_ERR_NOT_FOUND
    ErrorCodeAndName(ESP_ERR_NOT_FOUND),                              /*   261 0x105 Requested resource not found */
#   endif
#   ifdef      ESP_ERR_NOT_SUPPORTED
    ErrorCodeAndName(ESP_ERR_NOT_SUPPORTED),                          /*   262 0x106 Operation or feature not supported */
#   endif
#   ifdef      ESP_ERR_TIMEOUT
    ErrorCodeAndName(ESP_ERR_TIMEOUT),                                /*   263 0x107 Operation timed out */
#   endif
#   ifdef      ESP_ERR_INVALID_RESPONSE
    ErrorCodeAndName(ESP_ERR_INVALID_RESPONSE),                       /*   264 0x108 Received response was invalid */
#   endif
#   ifdef      ESP_ERR_INVALID_CRC
    ErrorCodeAndName(ESP_ERR_INVALID_CRC),                            /*   265 0x109 CRC or checksum was invalid */
#   endif
#   ifdef      ESP_ERR_INVALID_VERSION
    ErrorCodeAndName(ESP_ERR_INVALID_VERSION),                        /*   266 0x10a Version was invalid */
#   endif
#   ifdef      ESP_ERR_INVALID_MAC
    ErrorCodeAndName(ESP_ERR_INVALID_MAC),                            /*   267 0x10b MAC address was invalid */
#   endif
    // components/esp_serial_slave_link/include/esp_serial_slave_link/essl.h
#   ifdef      ESP_ERR_NOT_FINISHED
    ErrorCodeAndName(ESP_ERR_NOT_FINISHED),                           /*   513 0x201 */
#   endif
    // components/nvs_flash/include/nvs.h
#   ifdef      ESP_ERR_NVS_BASE
    ErrorCodeAndName(ESP_ERR_NVS_BASE),                               /*  4352 0x1100 Starting number of error codes */
#   endif
#   ifdef      ESP_ERR_NVS_NOT_INITIALIZED
    ErrorCodeAndName(ESP_ERR_NVS_NOT_INITIALIZED),                    /*  4353 0x1101 The storage driver is not initialized */
#   endif
#   ifdef      ESP_ERR_NVS_NOT_FOUND
    ErrorCodeAndName(ESP_ERR_NVS_NOT_FOUND),                          /*  4354 0x1102 Id namespace doesn’t exist yet and mode
                                                                                is NVS_READONLY */
#   endif
#   ifdef      ESP_ERR_NVS_TYPE_MISMATCH
    ErrorCodeAndName(ESP_ERR_NVS_TYPE_MISMATCH),                      /*  4355 0x1103 The type of set or get operation doesn't
                                                                                match the type of value stored in NVS */
#   endif
#   ifdef      ESP_ERR_NVS_READ_ONLY
    ErrorCodeAndName(ESP_ERR_NVS_READ_ONLY),                          /*  4356 0x1104 Storage handle was opened as read only */
#   endif
#   ifdef      ESP_ERR_NVS_NOT_ENOUGH_SPACE
    ErrorCodeAndName(ESP_ERR_NVS_NOT_ENOUGH_SPACE),                   /*  4357 0x1105 There is not enough space in the
                                                                                underlying storage to save the value */
#   endif
#   ifdef      ESP_ERR_NVS_INVALID_NAME
    ErrorCodeAndName(ESP_ERR_NVS_INVALID_NAME),                       /*  4358 0x1106 Namespace name doesn’t satisfy constraints */
#   endif
#   ifdef      ESP_ERR_NVS_INVALID_HANDLE
    ErrorCodeAndName(ESP_ERR_NVS_INVALID_HANDLE),                     /*  4359 0x1107 Handle has been closed or is NULL */
#   endif
#   ifdef      ESP_ERR_NVS_REMOVE_FAILED
    ErrorCodeAndName(ESP_ERR_NVS_REMOVE_FAILED),                      /*  4360 0x1108 The value wasn’t updated because flash
                                                                                write operation has failed. The value
                                                                                was written however, and update will be
                                                                                finished after re-initialization of nvs,
                                                                                provided that flash operation doesn’t
                                                                                fail again. */
#   endif
#   ifdef      ESP_ERR_NVS_KEY_TOO_LONG
    ErrorCodeAndName(ESP_ERR_NVS_KEY_TOO_LONG),                       /*  4361 0x1109 Key name is too long */
#   endif
#   ifdef      ESP_ERR_NVS_PAGE_FULL
    ErrorCodeAndName(ESP_ERR_NVS_PAGE_FULL),                          /*  4362 0x110a Internal error; never returned by nvs
                                                                                API functions */
#   endif
#   ifdef      ESP_ERR_NVS_INVALID_STATE
    ErrorCodeAndName(ESP_ERR_NVS_INVALID_STATE),                      /*  4363 0x110b NVS is in an inconsistent state due to a
                                                                                previous error. Call nvs_flash_init and
                                                                                nvs_open again, then retry. */
#   endif
#   ifdef      ESP_ERR_NVS_INVALID_LENGTH
    ErrorCodeAndName(ESP_ERR_NVS_INVALID_LENGTH),                     /*  4364 0x110c String or blob length is not sufficient
                                                                                to store data */
#   endif
#   ifdef      ESP_ERR_NVS_NO_FREE_PAGES
    ErrorCodeAndName(ESP_ERR_NVS_NO_FREE_PAGES),                      /*  4365 0x110d NVS partition doesn't contain any empty
                                                                                pages. This may happen if NVS partition
                                                                                was truncated. Erase the whole partition
                                                                                and call nvs_flash_init again. */
#   endif
#   ifdef      ESP_ERR_NVS_VALUE_TOO_LONG
    ErrorCodeAndName(ESP_ERR_NVS_VALUE_TOO_LONG),                     /*  4366 0x110e String or blob length is longer than
                                                                                supported by the implementation */
#   endif
#   ifdef      ESP_ERR_NVS_PART_NOT_FOUND
    ErrorCodeAndName(ESP_ERR_NVS_PART_NOT_FOUND),                     /*  4367 0x110f Partition with specified name is not
                                                                                found in the partition table */
#   endif
#   ifdef      ESP_ERR_NVS_NEW_VERSION_FOUND
    ErrorCodeAndName(ESP_ERR_NVS_NEW_VERSION_FOUND),                  /*  4368 0x1110 NVS partition contains data in new
                                                                                format and cannot be recognized by this
                                                                                version of code */
#   endif
#   ifdef      ESP_ERR_NVS_XTS_ENCR_FAILED
    ErrorCodeAndName(ESP_ERR_NVS_XTS_ENCR_FAILED),                    /*  4369 0x1111 XTS encryption failed while writing NVS entry */
#   endif
#   ifdef      ESP_ERR_NVS_XTS_DECR_FAILED
    ErrorCodeAndName(ESP_ERR_NVS_XTS_DECR_FAILED),                    /*  4370 0x1112 XTS decryption failed while reading NVS entry */
#   endif
#   ifdef      ESP_ERR_NVS_XTS_CFG_FAILED
    ErrorCodeAndName(ESP_ERR_NVS_XTS_CFG_FAILED),                     /*  4371 0x1113 XTS configuration setting failed */
#   endif
#   ifdef      ESP_ERR_NVS_XTS_CFG_NOT_FOUND
    ErrorCodeAndName(ESP_ERR_NVS_XTS_CFG_NOT_FOUND),                  /*  4372 0x1114 XTS configuration not found */
#   endif
#   ifdef      ESP_ERR_NVS_ENCR_NOT_SUPPORTED
    ErrorCodeAndName(ESP_ERR_NVS_ENCR_NOT_SUPPORTED),                 /*  4373 0x1115 NVS encryption is not supported in this version */
#   endif
#   ifdef      ESP_ERR_NVS_KEYS_NOT_INITIALIZED
    ErrorCodeAndName(ESP_ERR_NVS_KEYS_NOT_INITIALIZED),               /*  4374 0x1116 NVS key partition is uninitialized */
#   endif
#   ifdef      ESP_ERR_NVS_CORRUPT_KEY_PART
    ErrorCodeAndName(ESP_ERR_NVS_CORRUPT_KEY_PART),                   /*  4375 0x1117 NVS key partition is corrupt */
#   endif
#   ifdef      ESP_ERR_NVS_CONTENT_DIFFERS
    ErrorCodeAndName(ESP_ERR_NVS_CONTENT_DIFFERS),                    /*  4376 0x1118 Internal error; never returned by nvs
                                                                                API functions.  NVS key is different in
                                                                                comparison */
#   endif
    // components/ulp/include/ulp_common.h
#   ifdef      ESP_ERR_ULP_BASE
    ErrorCodeAndName(ESP_ERR_ULP_BASE),                               /*  4608 0x1200 Offset for ULP-related error codes */
#   endif
#   ifdef      ESP_ERR_ULP_SIZE_TOO_BIG
    ErrorCodeAndName(ESP_ERR_ULP_SIZE_TOO_BIG),                       /*  4609 0x1201 Program doesn't fit into RTC memory
                                                                                reserved for the ULP */
#   endif
#   ifdef      ESP_ERR_ULP_INVALID_LOAD_ADDR
    ErrorCodeAndName(ESP_ERR_ULP_INVALID_LOAD_ADDR),                  /*  4610 0x1202 Load address is outside of RTC memory
                                                                                reserved for the ULP */
#   endif
#   ifdef      ESP_ERR_ULP_DUPLICATE_LABEL
    ErrorCodeAndName(ESP_ERR_ULP_DUPLICATE_LABEL),                    /*  4611 0x1203 More than one label with the same number
                                                                                was defined */
#   endif
#   ifdef      ESP_ERR_ULP_UNDEFINED_LABEL
    ErrorCodeAndName(ESP_ERR_ULP_UNDEFINED_LABEL),                    /*  4612 0x1204 Branch instructions references an undefined label */
#   endif
#   ifdef      ESP_ERR_ULP_BRANCH_OUT_OF_RANGE
    ErrorCodeAndName(ESP_ERR_ULP_BRANCH_OUT_OF_RANGE),                /*  4613 0x1205 Branch target is out of range of B
                                                                                instruction (try replacing with BX) */
#   endif
    // components/app_update/include/esp_ota_ops.h
#   ifdef      ESP_ERR_OTA_BASE
    ErrorCodeAndName(ESP_ERR_OTA_BASE),                               /*  5376 0x1500 Base error code for ota_ops api */
#   endif
#   ifdef      ESP_ERR_OTA_PARTITION_CONFLICT
    ErrorCodeAndName(ESP_ERR_OTA_PARTITION_CONFLICT),                 /*  5377 0x1501 Error if request was to write or erase
                                                                                the current running partition */
#   endif
#   ifdef      ESP_ERR_OTA_SELECT_INFO_INVALID
    ErrorCodeAndName(ESP_ERR_OTA_SELECT_INFO_INVALID),                /*  5378 0x1502 Error if OTA data partition contains
                                                                                invalid content */
#   endif
#   ifdef      ESP_ERR_OTA_VALIDATE_FAILED
    ErrorCodeAndName(ESP_ERR_OTA_VALIDATE_FAILED),                    /*  5379 0x1503 Error if OTA app image is invalid */
#   endif
#   ifdef      ESP_ERR_OTA_SMALL_SEC_VER
    ErrorCodeAndName(ESP_ERR_OTA_SMALL_SEC_VER),                      /*  5380 0x1504 Error if the firmware has a secure
                                                                                version less than the running firmware. */
#   endif
#   ifdef      ESP_ERR_OTA_ROLLBACK_FAILED
    ErrorCodeAndName(ESP_ERR_OTA_ROLLBACK_FAILED),                    /*  5381 0x1505 Error if flash does not have valid
                                                                                firmware in passive partition and hence
                                                                                rollback is not possible */
#   endif
#   ifdef      ESP_ERR_OTA_ROLLBACK_INVALID_STATE
    ErrorCodeAndName(ESP_ERR_OTA_ROLLBACK_INVALID_STATE),             /*  5382 0x1506 Error if current active firmware is
                                                                                still marked in pending validation state
                                                                                (ESP_OTA_IMG_PENDING_VERIFY),
                                                                                essentially first boot of firmware image
                                                                                post upgrade and hence firmware upgrade
                                                                                is not possible */
#   endif
    // components/efuse/include/esp_efuse.h
#   ifdef      ESP_ERR_EFUSE
    ErrorCodeAndName(ESP_ERR_EFUSE),                                  /*  5632 0x1600 Base error code for efuse api. */
#   endif
#   ifdef      ESP_OK_EFUSE_CNT
    ErrorCodeAndName(ESP_OK_EFUSE_CNT),                               /*  5633 0x1601 OK the required number of bits is set. */
#   endif
#   ifdef      ESP_ERR_EFUSE_CNT_IS_FULL
    ErrorCodeAndName(ESP_ERR_EFUSE_CNT_IS_FULL),                      /*  5634 0x1602 Error field is full. */
#   endif
#   ifdef      ESP_ERR_EFUSE_REPEATED_PROG
    ErrorCodeAndName(ESP_ERR_EFUSE_REPEATED_PROG),                    /*  5635 0x1603 Error repeated programming of programmed
                                                                                bits is strictly forbidden. */
#   endif
#   ifdef      ESP_ERR_CODING
    ErrorCodeAndName(ESP_ERR_CODING),                                 /*  5636 0x1604 Error while a encoding operation. */
#   endif
    // components/bootloader_support/include/esp_image_format.h
#   ifdef      ESP_ERR_IMAGE_BASE
    ErrorCodeAndName(ESP_ERR_IMAGE_BASE),                             /*  8192 0x2000 */
#   endif
#   ifdef      ESP_ERR_IMAGE_FLASH_FAIL
    ErrorCodeAndName(ESP_ERR_IMAGE_FLASH_FAIL),                       /*  8193 0x2001 */
#   endif
#   ifdef      ESP_ERR_IMAGE_INVALID
    ErrorCodeAndName(ESP_ERR_IMAGE_INVALID),                          /*  8194 0x2002 */
#   endif
    // components/esp_common/include/esp_err.h
#   ifdef      ESP_ERR_WIFI_BASE
    ErrorCodeAndName(ESP_ERR_WIFI_BASE),                              /* 12288 0x3000 Starting number of WiFi error codes */
#   endif
    // components/esp_wifi/include/esp_wifi.h
#   ifdef      ESP_ERR_WIFI_NOT_INIT
    ErrorCodeAndName(ESP_ERR_WIFI_NOT_INIT),                          /* 12289 0x3001 WiFi driver was not installed by esp_wifi_init */
#   endif
#   ifdef      ESP_ERR_WIFI_NOT_STARTED
    ErrorCodeAndName(ESP_ERR_WIFI_NOT_STARTED),                       /* 12290 0x3002 WiFi driver was not started by esp_wifi_start */
#   endif
#   ifdef      ESP_ERR_WIFI_NOT_STOPPED
    ErrorCodeAndName(ESP_ERR_WIFI_NOT_STOPPED),                       /* 12291 0x3003 WiFi driver was not stopped by esp_wifi_stop */
#   endif
#   ifdef      ESP_ERR_WIFI_IF
    ErrorCodeAndName(ESP_ERR_WIFI_IF),                                /* 12292 0x3004 WiFi interface error */
#   endif
#   ifdef      ESP_ERR_WIFI_MODE
    ErrorCodeAndName(ESP_ERR_WIFI_MODE),                              /* 12293 0x3005 WiFi mode error */
#   endif
#   ifdef      ESP_ERR_WIFI_STATE
    ErrorCodeAndName(ESP_ERR_WIFI_STATE),                             /* 12294 0x3006 WiFi internal state error */
#   endif
#   ifdef      ESP_ERR_WIFI_CONN
    ErrorCodeAndName(ESP_ERR_WIFI_CONN),                              /* 12295 0x3007 WiFi internal control block of station
                                                                                or soft-AP error */
#   endif
#   ifdef      ESP_ERR_WIFI_NVS
    ErrorCodeAndName(ESP_ERR_WIFI_NVS),                               /* 12296 0x3008 WiFi internal NVS module error */
#   endif
#   ifdef      ESP_ERR_WIFI_MAC
    ErrorCodeAndName(ESP_ERR_WIFI_MAC),                               /* 12297 0x3009 MAC address is invalid */
#   endif
#   ifdef      ESP_ERR_WIFI_SSID
    ErrorCodeAndName(ESP_ERR_WIFI_SSID),                              /* 12298 0x300a SSID is invalid */
#   endif
#   ifdef      ESP_ERR_WIFI_PASSWORD
    ErrorCodeAndName(ESP_ERR_WIFI_PASSWORD),                          /* 12299 0x300b Password is invalid */
#   endif
#   ifdef      ESP_ERR_WIFI_TIMEOUT
    ErrorCodeAndName(ESP_ERR_WIFI_TIMEOUT),                           /* 12300 0x300c Timeout error */
#   endif
#   ifdef      ESP_ERR_WIFI_WAKE_FAIL
    ErrorCodeAndName(ESP_ERR_WIFI_WAKE_FAIL),                         /* 12301 0x300d WiFi is in sleep state(RF closed) and wakeup fail */
#   endif
#   ifdef      ESP_ERR_WIFI_WOULD_BLOCK
    ErrorCodeAndName(ESP_ERR_WIFI_WOULD_BLOCK),                       /* 12302 0x300e The caller would block */
#   endif
#   ifdef      ESP_ERR_WIFI_NOT_CONNECT
    ErrorCodeAndName(ESP_ERR_WIFI_NOT_CONNECT),                       /* 12303 0x300f Station still in disconnect status */
#   endif
#   ifdef      ESP_ERR_WIFI_POST
    ErrorCodeAndName(ESP_ERR_WIFI_POST),                              /* 12306 0x3012 Failed to post the event to WiFi task */
#   endif
#   ifdef      ESP_ERR_WIFI_INIT_STATE
    ErrorCodeAndName(ESP_ERR_WIFI_INIT_STATE),                        /* 12307 0x3013 Invalod WiFi state when init/deinit is called */
#   endif
#   ifdef      ESP_ERR_WIFI_STOP_STATE
    ErrorCodeAndName(ESP_ERR_WIFI_STOP_STATE),                        /* 12308 0x3014 Returned when WiFi is stopping */
#   endif
    // components/wpa_supplicant/include/esp_supplicant/esp_wps.h
#   ifdef      ESP_ERR_WIFI_REGISTRAR
    ErrorCodeAndName(ESP_ERR_WIFI_REGISTRAR),                         /* 12339 0x3033 WPS registrar is not supported */
#   endif
#   ifdef      ESP_ERR_WIFI_WPS_TYPE
    ErrorCodeAndName(ESP_ERR_WIFI_WPS_TYPE),                          /* 12340 0x3034 WPS type error */
#   endif
#   ifdef      ESP_ERR_WIFI_WPS_SM
    ErrorCodeAndName(ESP_ERR_WIFI_WPS_SM),                            /* 12341 0x3035 WPS state machine is not initialized */
#   endif
    // components/esp_wifi/include/esp_now.h
#   ifdef      ESP_ERR_ESPNOW_BASE
    ErrorCodeAndName(ESP_ERR_ESPNOW_BASE),                            /* 12388 0x3064 ESPNOW error number base. */
#   endif
#   ifdef      ESP_ERR_ESPNOW_NOT_INIT
    ErrorCodeAndName(ESP_ERR_ESPNOW_NOT_INIT),                        /* 12389 0x3065 ESPNOW is not initialized. */
#   endif
#   ifdef      ESP_ERR_ESPNOW_ARG
    ErrorCodeAndName(ESP_ERR_ESPNOW_ARG),                             /* 12390 0x3066 Invalid argument */
#   endif
#   ifdef      ESP_ERR_ESPNOW_NO_MEM
    ErrorCodeAndName(ESP_ERR_ESPNOW_NO_MEM),                          /* 12391 0x3067 Out of memory */
#   endif
#   ifdef      ESP_ERR_ESPNOW_FULL
    ErrorCodeAndName(ESP_ERR_ESPNOW_FULL),                            /* 12392 0x3068 ESPNOW peer list is full */
#   endif
#   ifdef      ESP_ERR_ESPNOW_NOT_FOUND
    ErrorCodeAndName(ESP_ERR_ESPNOW_NOT_FOUND),                       /* 12393 0x3069 ESPNOW peer is not found */
#   endif
#   ifdef      ESP_ERR_ESPNOW_INTERNAL
    ErrorCodeAndName(ESP_ERR_ESPNOW_INTERNAL),                        /* 12394 0x306a Internal error */
#   endif
#   ifdef      ESP_ERR_ESPNOW_EXIST
    ErrorCodeAndName(ESP_ERR_ESPNOW_EXIST),                           /* 12395 0x306b ESPNOW peer has existed */
#   endif
#   ifdef      ESP_ERR_ESPNOW_IF
    ErrorCodeAndName(ESP_ERR_ESPNOW_IF),                              /* 12396 0x306c Interface error */
#   endif
    // components/esp_common/include/esp_err.h
#   ifdef      ESP_ERR_MESH_BASE
    ErrorCodeAndName(ESP_ERR_MESH_BASE),                              /* 16384 0x4000 Starting number of MESH error codes */
#   endif
    // components/esp_wifi/include/esp_mesh.h
#   ifdef      ESP_ERR_MESH_WIFI_NOT_START
    ErrorCodeAndName(ESP_ERR_MESH_WIFI_NOT_START),                    /* 16385 0x4001 */
#   endif
#   ifdef      ESP_ERR_MESH_NOT_INIT
    ErrorCodeAndName(ESP_ERR_MESH_NOT_INIT),                          /* 16386 0x4002 */
#   endif
#   ifdef      ESP_ERR_MESH_NOT_CONFIG
    ErrorCodeAndName(ESP_ERR_MESH_NOT_CONFIG),                        /* 16387 0x4003 */
#   endif
#   ifdef      ESP_ERR_MESH_NOT_START
    ErrorCodeAndName(ESP_ERR_MESH_NOT_START),                         /* 16388 0x4004 */
#   endif
#   ifdef      ESP_ERR_MESH_NOT_SUPPORT
    ErrorCodeAndName(ESP_ERR_MESH_NOT_SUPPORT),                       /* 16389 0x4005 */
#   endif
#   ifdef      ESP_ERR_MESH_NOT_ALLOWED
    ErrorCodeAndName(ESP_ERR_MESH_NOT_ALLOWED),                       /* 16390 0x4006 */
#   endif
#   ifdef      ESP_ERR_MESH_NO_MEMORY
    ErrorCodeAndName(ESP_ERR_MESH_NO_MEMORY),                         /* 16391 0x4007 */
#   endif
#   ifdef      ESP_ERR_MESH_ARGUMENT
    ErrorCodeAndName(ESP_ERR_MESH_ARGUMENT),                          /* 16392 0x4008 */
#   endif
#   ifdef      ESP_ERR_MESH_EXCEED_MTU
    ErrorCodeAndName(ESP_ERR_MESH_EXCEED_MTU),                        /* 16393 0x4009 */
#   endif
#   ifdef      ESP_ERR_MESH_TIMEOUT
    ErrorCodeAndName(ESP_ERR_MESH_TIMEOUT),                           /* 16394 0x400a */
#   endif
#   ifdef      ESP_ERR_MESH_DISCONNECTED
    ErrorCodeAndName(ESP_ERR_MESH_DISCONNECTED),                      /* 16395 0x400b */
#   endif
#   ifdef      ESP_ERR_MESH_QUEUE_FAIL
    ErrorCodeAndName(ESP_ERR_MESH_QUEUE_FAIL),                        /* 16396 0x400c */
#   endif
#   ifdef      ESP_ERR_MESH_QUEUE_FULL
    ErrorCodeAndName(ESP_ERR_MESH_QUEUE_FULL),                        /* 16397 0x400d */
#   endif
#   ifdef      ESP_ERR_MESH_NO_PARENT_FOUND
    ErrorCodeAndName(ESP_ERR_MESH_NO_PARENT_FOUND),                   /* 16398 0x400e */
#   endif
#   ifdef      ESP_ERR_MESH_NO_ROUTE_FOUND
    ErrorCodeAndName(ESP_ERR_MESH_NO_ROUTE_FOUND),                    /* 16399 0x400f */
#   endif
#   ifdef      ESP_ERR_MESH_OPTION_NULL
    ErrorCodeAndName(ESP_ERR_MESH_OPTION_NULL),                       /* 16400 0x4010 */
#   endif
#   ifdef      ESP_ERR_MESH_OPTION_UNKNOWN
    ErrorCodeAndName(ESP_ERR_MESH_OPTION_UNKNOWN),                    /* 16401 0x4011 */
#   endif
#   ifdef      ESP_ERR_MESH_XON_NO_WINDOW
    ErrorCodeAndName(ESP_ERR_MESH_XON_NO_WINDOW),                     /* 16402 0x4012 */
#   endif
#   ifdef      ESP_ERR_MESH_INTERFACE
    ErrorCodeAndName(ESP_ERR_MESH_INTERFACE),                         /* 16403 0x4013 */
#   endif
#   ifdef      ESP_ERR_MESH_DISCARD_DUPLICATE
    ErrorCodeAndName(ESP_ERR_MESH_DISCARD_DUPLICATE),                 /* 16404 0x4014 */
#   endif
#   ifdef      ESP_ERR_MESH_DISCARD
    ErrorCodeAndName(ESP_ERR_MESH_DISCARD),                           /* 16405 0x4015 */
#   endif
#   ifdef      ESP_ERR_MESH_VOTING
    ErrorCodeAndName(ESP_ERR_MESH_VOTING),                            /* 16406 0x4016 */
#   endif
    // components/esp_netif/include/esp_netif_types.h
#   ifdef      ESP_ERR_ESP_NETIF_BASE
    ErrorCodeAndName(ESP_ERR_ESP_NETIF_BASE),                         /* 20480 0x5000 */
#   endif
#   ifdef      ESP_ERR_ESP_NETIF_INVALID_PARAMS
    ErrorCodeAndName(ESP_ERR_ESP_NETIF_INVALID_PARAMS),               /* 20481 0x5001 */
#   endif
#   ifdef      ESP_ERR_ESP_NETIF_IF_NOT_READY
    ErrorCodeAndName(ESP_ERR_ESP_NETIF_IF_NOT_READY),                 /* 20482 0x5002 */
#   endif
#   ifdef      ESP_ERR_ESP_NETIF_DHCPC_START_FAILED
    ErrorCodeAndName(ESP_ERR_ESP_NETIF_DHCPC_START_FAILED),           /* 20483 0x5003 */
#   endif
#   ifdef      ESP_ERR_ESP_NETIF_DHCP_ALREADY_STARTED
    ErrorCodeAndName(ESP_ERR_ESP_NETIF_DHCP_ALREADY_STARTED),         /* 20484 0x5004 */
#   endif
#   ifdef      ESP_ERR_ESP_NETIF_DHCP_ALREADY_STOPPED
    ErrorCodeAndName(ESP_ERR_ESP_NETIF_DHCP_ALREADY_STOPPED),         /* 20485 0x5005 */
#   endif
#   ifdef      ESP_ERR_ESP_NETIF_NO_MEM
    ErrorCodeAndName(ESP_ERR_ESP_NETIF_NO_MEM),                       /* 20486 0x5006 */
#   endif
#   ifdef      ESP_ERR_ESP_NETIF_DHCP_NOT_STOPPED
    ErrorCodeAndName(ESP_ERR_ESP_NETIF_DHCP_NOT_STOPPED),             /* 20487 0x5007 */
#   endif
#   ifdef      ESP_ERR_ESP_NETIF_DRIVER_ATTACH_FAILED
    ErrorCodeAndName(ESP_ERR_ESP_NETIF_DRIVER_ATTACH_FAILED),         /* 20488 0x5008 */
#   endif
#   ifdef      ESP_ERR_ESP_NETIF_INIT_FAILED
    ErrorCodeAndName(ESP_ERR_ESP_NETIF_INIT_FAILED),                  /* 20489 0x5009 */
#   endif
#   ifdef      ESP_ERR_ESP_NETIF_DNS_NOT_CONFIGURED
    ErrorCodeAndName(ESP_ERR_ESP_NETIF_DNS_NOT_CONFIGURED),           /* 20490 0x500a */
#   endif
    // components/esp_common/include/esp_err.h
#   ifdef      ESP_ERR_FLASH_BASE
    ErrorCodeAndName(ESP_ERR_FLASH_BASE),                             /* 24576 0x6000 Starting number of flash error codes */
#   endif
    // components/spi_flash/include/esp_spi_flash.h
#   ifdef      ESP_ERR_FLASH_OP_FAIL
    ErrorCodeAndName(ESP_ERR_FLASH_OP_FAIL),                          /* 24577 0x6001 */
#   endif
#   ifdef      ESP_ERR_FLASH_OP_TIMEOUT
    ErrorCodeAndName(ESP_ERR_FLASH_OP_TIMEOUT),                       /* 24578 0x6002 */
#   endif
    // components/soc/include/hal/esp_flash_err.h
#   ifdef      ESP_ERR_FLASH_NOT_INITIALISED
    ErrorCodeAndName(ESP_ERR_FLASH_NOT_INITIALISED),                  /* 24579 0x6003 */
#   endif
#   ifdef      ESP_ERR_FLASH_UNSUPPORTED_HOST
    ErrorCodeAndName(ESP_ERR_FLASH_UNSUPPORTED_HOST),                 /* 24580 0x6004 */
#   endif
#   ifdef      ESP_ERR_FLASH_UNSUPPORTED_CHIP
    ErrorCodeAndName(ESP_ERR_FLASH_UNSUPPORTED_CHIP),                 /* 24581 0x6005 */
#   endif
#   ifdef      ESP_ERR_FLASH_PROTECTED
    ErrorCodeAndName(ESP_ERR_FLASH_PROTECTED),                        /* 24582 0x6006 */
#   endif
    // components/esp_http_client/include/esp_http_client.h
#   ifdef      ESP_ERR_HTTP_BASE
    ErrorCodeAndName(ESP_ERR_HTTP_BASE),                              /* 28672 0x7000 Starting number of HTTP error codes */
#   endif
#   ifdef      ESP_ERR_HTTP_MAX_REDIRECT
    ErrorCodeAndName(ESP_ERR_HTTP_MAX_REDIRECT),                      /* 28673 0x7001 The error exceeds the number of HTTP redirects */
#   endif
#   ifdef      ESP_ERR_HTTP_CONNECT
    ErrorCodeAndName(ESP_ERR_HTTP_CONNECT),                           /* 28674 0x7002 Error open the HTTP connection */
#   endif
#   ifdef      ESP_ERR_HTTP_WRITE_DATA
    ErrorCodeAndName(ESP_ERR_HTTP_WRITE_DATA),                        /* 28675 0x7003 Error write HTTP data */
#   endif
#   ifdef      ESP_ERR_HTTP_FETCH_HEADER
    ErrorCodeAndName(ESP_ERR_HTTP_FETCH_HEADER),                      /* 28676 0x7004 Error read HTTP header from server */
#   endif
#   ifdef      ESP_ERR_HTTP_INVALID_TRANSPORT
    ErrorCodeAndName(ESP_ERR_HTTP_INVALID_TRANSPORT),                 /* 28677 0x7005 There are no transport support for the
                                                                                input scheme */
#   endif
#   ifdef      ESP_ERR_HTTP_CONNECTING
    ErrorCodeAndName(ESP_ERR_HTTP_CONNECTING),                        /* 28678 0x7006 HTTP connection hasn't been established yet */
#   endif
#   ifdef      ESP_ERR_HTTP_EAGAIN
    ErrorCodeAndName(ESP_ERR_HTTP_EAGAIN),                            /* 28679 0x7007 Mapping of errno EAGAIN to esp_err_t */
#   endif
    // components/esp-tls/esp_tls.h
#   ifdef      ESP_ERR_ESP_TLS_BASE
    ErrorCodeAndName(ESP_ERR_ESP_TLS_BASE),                           /* 32768 0x8000 Starting number of ESP-TLS error codes */
#   endif
#   ifdef      ESP_ERR_ESP_TLS_CANNOT_RESOLVE_HOSTNAME
    ErrorCodeAndName(ESP_ERR_ESP_TLS_CANNOT_RESOLVE_HOSTNAME),        /* 32769 0x8001 Error if hostname couldn't be resolved
                                                                                upon tls connection */
#   endif
#   ifdef      ESP_ERR_ESP_TLS_CANNOT_CREATE_SOCKET
    ErrorCodeAndName(ESP_ERR_ESP_TLS_CANNOT_CREATE_SOCKET),           /* 32770 0x8002 Failed to create socket */
#   endif
#   ifdef      ESP_ERR_ESP_TLS_UNSUPPORTED_PROTOCOL_FAMILY
    ErrorCodeAndName(ESP_ERR_ESP_TLS_UNSUPPORTED_PROTOCOL_FAMILY),    /* 32771 0x8003 Unsupported protocol family */
#   endif
#   ifdef      ESP_ERR_ESP_TLS_FAILED_CONNECT_TO_HOST
    ErrorCodeAndName(ESP_ERR_ESP_TLS_FAILED_CONNECT_TO_HOST),         /* 32772 0x8004 Failed to connect to host */
#   endif
#   ifdef      ESP_ERR_ESP_TLS_SOCKET_SETOPT_FAILED
    ErrorCodeAndName(ESP_ERR_ESP_TLS_SOCKET_SETOPT_FAILED),           /* 32773 0x8005 failed to set socket option */
#   endif
#   ifdef      ESP_ERR_MBEDTLS_CERT_PARTLY_OK
    ErrorCodeAndName(ESP_ERR_MBEDTLS_CERT_PARTLY_OK),                 /* 32774 0x8006 mbedtls parse certificates was partly successful */
#   endif
#   ifdef      ESP_ERR_MBEDTLS_CTR_DRBG_SEED_FAILED
    ErrorCodeAndName(ESP_ERR_MBEDTLS_CTR_DRBG_SEED_FAILED),           /* 32775 0x8007 mbedtls api returned error */
#   endif
#   ifdef      ESP_ERR_MBEDTLS_SSL_SET_HOSTNAME_FAILED
    ErrorCodeAndName(ESP_ERR_MBEDTLS_SSL_SET_HOSTNAME_FAILED),        /* 32776 0x8008 mbedtls api returned error */
#   endif
#   ifdef      ESP_ERR_MBEDTLS_SSL_CONFIG_DEFAULTS_FAILED
    ErrorCodeAndName(ESP_ERR_MBEDTLS_SSL_CONFIG_DEFAULTS_FAILED),     /* 32777 0x8009 mbedtls api returned error */
#   endif
#   ifdef      ESP_ERR_MBEDTLS_SSL_CONF_ALPN_PROTOCOLS_FAILED
    ErrorCodeAndName(ESP_ERR_MBEDTLS_SSL_CONF_ALPN_PROTOCOLS_FAILED), /* 32778 0x800a mbedtls api returned error */
#   endif
#   ifdef      ESP_ERR_MBEDTLS_X509_CRT_PARSE_FAILED
    ErrorCodeAndName(ESP_ERR_MBEDTLS_X509_CRT_PARSE_FAILED),          /* 32779 0x800b mbedtls api returned error */
#   endif
#   ifdef      ESP_ERR_MBEDTLS_SSL_CONF_OWN_CERT_FAILED
    ErrorCodeAndName(ESP_ERR_MBEDTLS_SSL_CONF_OWN_CERT_FAILED),       /* 32780 0x800c mbedtls api returned error */
#   endif
#   ifdef      ESP_ERR_MBEDTLS_SSL_SETUP_FAILED
    ErrorCodeAndName(ESP_ERR_MBEDTLS_SSL_SETUP_FAILED),               /* 32781 0x800d mbedtls api returned error */
#   endif
#   ifdef      ESP_ERR_MBEDTLS_SSL_WRITE_FAILED
    ErrorCodeAndName(ESP_ERR_MBEDTLS_SSL_WRITE_FAILED),               /* 32782 0x800e mbedtls api returned error */
#   endif
#   ifdef      ESP_ERR_MBEDTLS_PK_PARSE_KEY_FAILED
    ErrorCodeAndName(ESP_ERR_MBEDTLS_PK_PARSE_KEY_FAILED),            /* 32783 0x800f mbedtls api returned failed */
#   endif
#   ifdef      ESP_ERR_MBEDTLS_SSL_HANDSHAKE_FAILED
    ErrorCodeAndName(ESP_ERR_MBEDTLS_SSL_HANDSHAKE_FAILED),           /* 32784 0x8010 mbedtls api returned failed */
#   endif
#   ifdef      ESP_ERR_MBEDTLS_SSL_CONF_PSK_FAILED
    ErrorCodeAndName(ESP_ERR_MBEDTLS_SSL_CONF_PSK_FAILED),            /* 32785 0x8011 mbedtls api returned failed */
#   endif
    // components/esp_https_ota/include/esp_https_ota.h
#   ifdef      ESP_ERR_HTTPS_OTA_BASE
    ErrorCodeAndName(ESP_ERR_HTTPS_OTA_BASE),                         /* 36864 0x9000 */
#   endif
#   ifdef      ESP_ERR_HTTPS_OTA_IN_PROGRESS
    ErrorCodeAndName(ESP_ERR_HTTPS_OTA_IN_PROGRESS),                  /* 36865 0x9001 */
#   endif
    // components/lwip/include/apps/esp_ping.h
#   ifdef      ESP_ERR_PING_BASE
    ErrorCodeAndName(ESP_ERR_PING_BASE),                              /* 40960 0xa000 */
#   endif
#   ifdef      ESP_ERR_PING_INVALID_PARAMS
    ErrorCodeAndName(ESP_ERR_PING_INVALID_PARAMS),                    /* 40961 0xa001 */
#   endif
#   ifdef      ESP_ERR_PING_NO_MEM
    ErrorCodeAndName(ESP_ERR_PING_NO_MEM),                            /* 40962 0xa002 */
#   endif
    // components/esp_http_server/include/esp_http_server.h
#   ifdef      ESP_ERR_HTTPD_BASE
    ErrorCodeAndName(ESP_ERR_HTTPD_BASE),                             /* 45056 0xb000 Starting number of HTTPD error codes */
#   endif
#   ifdef      ESP_ERR_HTTPD_HANDLERS_FULL
    ErrorCodeAndName(ESP_ERR_HTTPD_HANDLERS_FULL),                    /* 45057 0xb001 All slots for registering URI handlers
                                                                                have been consumed */
#   endif
#   ifdef      ESP_ERR_HTTPD_HANDLER_EXISTS
    ErrorCodeAndName(ESP_ERR_HTTPD_HANDLER_EXISTS),                   /* 45058 0xb002 URI handler with same method and target
                                                                                URI already registered */
#   endif
#   ifdef      ESP_ERR_HTTPD_INVALID_REQ
    ErrorCodeAndName(ESP_ERR_HTTPD_INVALID_REQ),                      /* 45059 0xb003 Invalid request pointer */
#   endif
#   ifdef      ESP_ERR_HTTPD_RESULT_TRUNC
    ErrorCodeAndName(ESP_ERR_HTTPD_RESULT_TRUNC),                     /* 45060 0xb004 Result string truncated */
#   endif
#   ifdef      ESP_ERR_HTTPD_RESP_HDR
    ErrorCodeAndName(ESP_ERR_HTTPD_RESP_HDR),                         /* 45061 0xb005 Response header field larger than supported */
#   endif
#   ifdef      ESP_ERR_HTTPD_RESP_SEND
    ErrorCodeAndName(ESP_ERR_HTTPD_RESP_SEND),                        /* 45062 0xb006 Error occured while sending response packet */
#   endif
#   ifdef      ESP_ERR_HTTPD_ALLOC_MEM
    ErrorCodeAndName(ESP_ERR_HTTPD_ALLOC_MEM),                        /* 45063 0xb007 Failed to dynamically allocate memory
                                                                                for resource */
#   endif
#   ifdef      ESP_ERR_HTTPD_TASK
    ErrorCodeAndName(ESP_ERR_HTTPD_TASK),                             /* 45064 0xb008 Failed to launch server task/thread */
#   endif
};