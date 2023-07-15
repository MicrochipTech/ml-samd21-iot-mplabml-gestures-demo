
/*******************************************************************************
* Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/

#ifndef _KB_TYPEDEFS_H_
#define _KB_TYPEDEFS_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef float FLOAT;
typedef signed short SENSOR_DATA_T;
typedef float FVCOMP_T;
typedef unsigned short NORMTYPE;

// clang-format off

/*
Expected sensor column ordering for each model

#define AX_S_GESTURE_RECOGNITION_PIPELINE_RANK_2 0
#define AY_S_GESTURE_RECOGNITION_PIPELINE_RANK_2 1
#define AZ_S_GESTURE_RECOGNITION_PIPELINE_RANK_2 2
#define GX_S_GESTURE_RECOGNITION_PIPELINE_RANK_2 3
#define GY_S_GESTURE_RECOGNITION_PIPELINE_RANK_2 4
#define GZ_S_GESTURE_RECOGNITION_PIPELINE_RANK_2 5

*/

#ifdef __cplusplus
extern "C"
{
#endif

struct compx
{
    float real;
    float imag;
};

struct compx_int16_t
{
    int16_t real;
    int16_t imag;
};

typedef struct
{
    uint16_t influence; //influence of a pattern
    uint16_t category;  //category of pattern
    uint8_t *vector;    // vector containing the features of a pattern
} pme_pattern_t;

typedef struct
{
    uint16_t number_patterns; //influence of a pattern
    uint16_t pattern_length;  //category of pattern
} pme_model_header_t;



/** @struct model_results
 *  @brief This structure is used to get the output of the classifier before the classification
 *  @var tf_micro_model_results::num_outputs 
 *  Number of classes in the model
 *  @var tf_micro_model_results::output_tensor 
 *  The final output tensor of the model used as input into the final classification layer
 */
typedef struct model_results
{
    uint8_t num_outputs; //number of outputs
    int16_t *output_tensor; //the output tensor results
} model_results_t;


/** KB Log levels. */
enum kb_log_levels
{
    KB_LOG_LEVEL_1 = 1, /*!< Default log level, classifier output */
    KB_LOG_CLASSIFIER_OUTPUT = KB_LOG_LEVEL_1,
    KB_LOG_LEVEL_2, /*!< A little verbose log level, feature output */
    KB_LOG_FEATURE_OUTPUT = KB_LOG_LEVEL_2,
    KB_LOG_LEVEL_3, /*!< Very Verbose log level, segmenter output */
    KB_LOG_SEGMENTER_OUTPUT = KB_LOG_LEVEL_3,
    KB_LOG_LEVEL_4, /*!< Very Very Verbose log level, kitchen sink included */
    KB_LOG_LEVEL_EVERYTHING = KB_LOG_LEVEL_4,
    KB_LOG_LEVEL_NUM = KB_LOG_LEVEL_4
};

#ifdef __cplusplus
}
#endif
// clang-format on

#endif //_KB_TYPEDEFS_H_
