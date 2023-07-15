
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

#ifndef _KB_DEBUG_H_
#define _KB_DEBUG_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include "kb_typedefs.h"
#include "kb_defines.h"
#include "kb.h"

    /**
* @brief Generates a string containing the model result information
*
* @param[in] model_index Model index to use
* @param[in] result result from most recent classification
* @param[in] pbuf char buffer to hold the string
* @param[in] feature_vector a bool, true to add feature vector information
* @param[in] fv_arr an arrary to store the feature vector results in
* @returns length of data put into pbuf
*/
    int32_t kb_print_model_result(int32_t model_index, int32_t result, char *pbuf, bool feature_vectors, uint8_t *fv_arr);

    /**
* @brief Fills a string with a json of the model output tensor
*
* @param[in] model_index Model index to use
* @param[in] result result from most recent classification
* @param[in] pbuf char buffer to hold the string
* @returns length of data put into pbuf
*/
int32_t kb_print_model_output_tensor(int32_t model_index, int32_t result, char* pbuf );

/**
* @brief Prints the model class map to a char string
*
* @param[in] model_index Model index to use
*/
void kb_print_model_class_map(int32_t model_index, char *output);
#define sml_print_model_class_map kb_print_model_class_map

void kb_print_model_map();

int32_t kb_print_model_cycles(
    int32_t model_index, char* pbuf, uint32_t* cycles);
int32_t kb_print_model_times(
    int32_t model_index, char* pbuf, float* times);

#ifdef __cplusplus
}
#endif

#endif // _KB_DEBUG_H_
