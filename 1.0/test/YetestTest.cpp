#define LOG_TAG "YetestTest"
#include <android/hardware/yetest/1.0/IYetest.h>
#include <android/hardware/yetest/1.0/types.h>
#include <hidl/Status.h>
#include <hidl/LegacySupport.h>
#include <hidl/HidlSupport.h>
#include <log/log.h>
#include <utils/misc.h>

using ::android::sp;
using namespace ::android::hardware::yetest::V1_0;

int main() {
    android::sp<IYetest> service = IYetest::getService();
    if (service == nullptr) {
        ALOGI("Failed to get yetest service");
        return -1;
    }

    YeData ye_data;
    service->getData([&ye_data](YeData ret) { ye_data = ret; });
    ALOGI("getData, ye_data.x=%d, ye_data.y=%d", ye_data.x, ye_data.y);
    // LOGD("ye_status=", (int)ye_status);
    YeStatus status = service->setData(ye_data);
    ALOGI("setData, status=%d", status);
    // LOGD("ye_status=", (int)ye_status);
    return 0;
}