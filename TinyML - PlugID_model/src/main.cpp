#include <Arduino.h>
#include <EloquentTinyML.h>


// copy the printed code from tinymlgen into this file
#include "digits_model.h"

#define NUMBER_OF_INPUTS 64
#define NUMBER_OF_OUTPUTS 12
#define TENSOR_ARENA_SIZE 32*1024

Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;

void setup() {
    Serial.begin(115200);
    ml.begin(PlugID_model);
}

void loop() {
    // a random sample from the MNIST dataset (precisely the last one)
    // float x_test[64]={};
    float x_test[64] ={0.        ,0.         ,0.        ,0.          ,0.          ,0.          ,0.51382749  ,0.9787461 ,
                       0.        ,0.         ,0.        ,0.          ,0.          ,0.39269022  ,0.49765807  ,0.        ,
                       0.        ,0.         ,0.        ,0.          ,0.14501047  ,0.55744745  ,0.          ,0.        ,
                       0.        ,0.         ,0.        ,0.08372184  ,0.59397284  ,0.13671719  ,0.          ,0.        ,
                       0.        ,0.         ,0.10808443,0.5959364   ,0.06835859  ,0.          ,0.          ,0.        ,
                       0.        ,0.         ,0.55534783,0.13671719  ,0.          ,0.          ,0.          ,0.        ,
                       0.        ,0.52060353 ,0.41580909,0.          ,0.          ,0.          ,0.          ,0.        ,
                       1.        ,0.49294082 ,0.        ,0.          ,0.          ,0.          ,0.          ,0.        };
    // the output vector for the model predictions
    // float y_pred[12] = {0};
    float y_pred[6] = {0};

    // the actual class of the sample
    int y_test = 9;

    // let's see how long it takes to classify the sample
    uint32_t start = micros();

    ml.predict(x_test, y_pred);

    uint32_t timeit = micros() - start;
    Serial.print("It took ");
    Serial.print(timeit);
    Serial.println(" micros to run inference");

    // let's print the raw predictions for all the classes
    // these values are not directly interpretable as probabilities!
    Serial.print("Test output is: ");
    Serial.println(y_test);
    Serial.print("Predicted proba are: ");

    for (int i = 0; i < 12; i++) {
        Serial.print(y_pred[i]);
        Serial.print(i == 11 ? '\n' : ',');
    }

    // let's print the "most probable" class
    // you can either use probaToClass() if you also want to use all the probabilities
    Serial.print("Predicted class is: ");
    Serial.println(ml.probaToClass(y_pred));
    // or you can skip the predict() method and call directly predictClass()
    Serial.print("Sanity check: ");
    Serial.println(ml.predictClass(x_test));

    delay(1000);
}