
#define LOG_TAG "yetest@1.0-service"
#include <iostream>
#include <memory>

#include <log/log.h>
#include <hidl/HidlTransportSupport.h>

#include "impl/Yetest.h"

using namespace android;
using namespace android::hardware;
using namespace android::hardware::yetest::V1_0::implementation;

int main(int /* argc */, char* /* argv */ []) {
    ALOGI("yetest start!");
	auto service = std::make_unique<Yetest>();

	configureRpcThreadpool(4, true /* callerWillJoin */);
	ALOGI("Registering as service...");
    status_t status = service->registerAsService();
    
    if (status != OK) {
        ALOGE("Unable to register yetest service (%d)", status);
        return 1;
    }

    ALOGI("yetesthal Ready");
    joinRpcThreadpool();

    return 1;
}
