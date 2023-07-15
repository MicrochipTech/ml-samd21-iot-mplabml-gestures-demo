#include "app_config.h"
#include "kb.h"
#include "sml_output.h"
#include "sml_recognition_run.h"
#include "peripheral/sercom/usart/plib_sercom5_usart.h"
#ifdef SML_USE_TEST_DATA
#include "testdata.h"
int32_t td_index = 0;
#endif // SML_USE_TEST_DATA

uint32_t runtime;
extern uint64_t read_timer_ms(void);

#define NUM_CLASSES 6u
/*
 * "1": "figeight",
 * "2": "idle",
 * "3": "unknown",
 * "4": "updown",
 * "5": "wave",
 * "6": "wheelcw",
 * "0": "Unknown"
 */
static uint8_t class_map[NUM_CLASSES] = {0u};

uint16_t sml_recognition_run(SNSR_DATA_TYPE *data, int32_t num_sensors)
{
    int32_t ret;
    //FILL_RUN_MODEL_MOTION_BMI160
    //FILL_RUN_MODEL_MOTION_ICM-42688-P
    runtime = read_timer_ms();
    ret = kb_run_model((SENSOR_DATA_T *)data, num_sensors, KB_MODEL_GESTURE_RECOGNITION_PIPELINE_RANK_2_INDEX);
    runtime = read_timer_ms() - runtime;
    if (ret >= 0){
        SERCOM5_USART_WriteByte(0xA5);
        class_map[0u] = 0u;//idle//
        class_map[1u] = 0u;//wave//
        class_map[2u] = 0u;//up-down//
        class_map[3u] = 0u;//wheel-clockwise
        class_map[4u] = 0u;//figure-eight//
        class_map[5u] = 0u;//unknown//
        switch(ret)
        {
            case 0u:
                class_map[5u]=1u;
                break;
            case 1u:
                class_map[4u]=1u;
                break;
            case 2u:
                class_map[0u]=1u;
                break;
            case 3u:
                class_map[5u]=1u;
                break;
            case 4u:
                class_map[2u]=1u;
                break;
            case 5u:
                class_map[1u]=1u;
                break;
            case 6u:
                class_map[3u]=1u;
                break;
        }
        SERCOM5_USART_Write(class_map,6u);
        SERCOM5_USART_Write(&runtime,4u);
        SERCOM5_USART_WriteByte(~0xA5);
        //sml_output_results(KB_MODEL_GESTURE_RECOGNITION_PIPELINE_RANK_0_INDEX, ret);
        kb_reset_model(0);
    };
    return ret;
}

// This function should never be called, but the compiler requires it to be defined
void __cxa_pure_virtual()
{
    printf("\n\n Application Failed!\n\n\n"); while (1){};
}