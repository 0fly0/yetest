#define LOG_TAG "Yetest"
#include "Yetest.h"

namespace android {
namespace hardware {
namespace yetest {
namespace V1_0 {
namespace implementation {

Yetest::Yetest(){
    ALOGI("Yetest()");
    m_thread = std::thread([this](){ loop(); });
}

Yetest::~Yetest(){
    ALOGI("~Yetest()");
}

// Methods from ::android::hardware::yetest::V1_0::IYetest follow.
Return<YeStatus> Yetest::setData(const YeData& data) {
    m_data = data;
    ALOGD("m_data.x=%d, m_data.y=%d", m_data.x, m_data.y);
    return YeStatus::SUCCESS;
}

Return<void> Yetest::getData(getData_cb _hidl_cb) {
    ALOGD("get data");
    _hidl_cb(m_data);
    return Void();
}

void Yetest::loop() {
    while(1) {
        sleep(1);
        ALOGI("Loop m_data.x=%d, m_data.y=%d", m_data.x, m_data.y);
    }
}

// Methods from ::android::hidl::base::V1_0::IBase follow.

//IYetest* HIDL_FETCH_IYetest(const char* /* name */) {
    //return new Yetest();
//}
//
}  // namespace implementation
}  // namespace V1_0
}  // namespace yetest
}  // namespace hardware
}  // namespace android
