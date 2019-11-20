#ifndef ANDROID_HARDWARE_YETEST_V1_0_YETEST_H
#define ANDROID_HARDWARE_YETEST_V1_0_YETEST_H

#include <android/hardware/yetest/1.0/IYetest.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <log/log.h>

#include <thread>

namespace android {
namespace hardware {
namespace yetest {
namespace V1_0 {
namespace implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct Yetest : public IYetest {
  public:
    Yetest();
    ~Yetest();
    // Methods from ::android::hardware::yetest::V1_0::IYetest follow.
    Return<YeStatus> setData(const YeData& data) override;
    Return<void> getData(getData_cb _hidl_cb) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.
  private:
    YeData m_data;
    std::thread m_thread;

    void loop();
};

// FIXME: most likely delete, this is only for passthrough implementations
// extern "C" IYetest* HIDL_FETCH_IYetest(const char* name);

}  // namespace implementation
}  // namespace V1_0
}  // namespace yetest
}  // namespace hardware
}  // namespace android

#endif  // ANDROID_HARDWARE_YETEST_V1_0_YETEST_H
