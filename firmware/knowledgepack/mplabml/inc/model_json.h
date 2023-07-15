#ifndef __MODEL_JSON_H__
#define __MODEL_JSON_H__

const char recognition_model_string_json[] = {"{\"NumModels\":1,\"ModelIndexes\":{\"0\":\"GESTURE_RECOGNITION_PIPELINE_RANK_2\"},\"ModelDescriptions\":[{\"Name\":\"GESTURE_RECOGNITION_PIPELINE_RANK_2\",\"ClassMaps\":{\"1\":\"figeight\",\"2\":\"idle\",\"3\":\"unknown\",\"4\":\"updown\",\"5\":\"wave\",\"6\":\"wheelcw\",\"0\":\"Unknown\"},\"ModelType\":\"PME\",\"FeatureFunctions\":[\"Minimum\",\"25thPercentile\",\"AbsoluteAreaofSpectrum\",\"Variance\",\"Variance\",\"InterquartileRange\",\"75thPercentile\",\"GlobalPeaktoPeakofLowFrequency\"]}]}"};

int32_t recognition_model_string_json_len = sizeof(recognition_model_string_json);

#endif /* __MODEL_JSON_H__ */
