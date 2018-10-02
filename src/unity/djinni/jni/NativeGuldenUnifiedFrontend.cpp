// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#include "NativeGuldenUnifiedFrontend.hpp"  // my header
#include "Marshal.hpp"
#include "NativeBalanceRecord.hpp"

namespace djinni_generated {

NativeGuldenUnifiedFrontend::NativeGuldenUnifiedFrontend() : ::djinni::JniInterface<::GuldenUnifiedFrontend, NativeGuldenUnifiedFrontend>() {}

NativeGuldenUnifiedFrontend::~NativeGuldenUnifiedFrontend() = default;

NativeGuldenUnifiedFrontend::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

NativeGuldenUnifiedFrontend::JavaProxy::~JavaProxy() = default;

bool NativeGuldenUnifiedFrontend::JavaProxy::notifySPVProgress(int32_t c_start_height, int32_t c_progess_height, int32_t c_expected_height) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeGuldenUnifiedFrontend>::get();
    auto jret = jniEnv->CallBooleanMethod(Handle::get().get(), data.method_notifySPVProgress,
                                          ::djinni::get(::djinni::I32::fromCpp(jniEnv, c_start_height)),
                                          ::djinni::get(::djinni::I32::fromCpp(jniEnv, c_progess_height)),
                                          ::djinni::get(::djinni::I32::fromCpp(jniEnv, c_expected_height)));
    ::djinni::jniExceptionCheck(jniEnv);
    return ::djinni::Bool::toCpp(jniEnv, jret);
}
bool NativeGuldenUnifiedFrontend::JavaProxy::notifyBalanceChange(const ::BalanceRecord & c_new_balance) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeGuldenUnifiedFrontend>::get();
    auto jret = jniEnv->CallBooleanMethod(Handle::get().get(), data.method_notifyBalanceChange,
                                          ::djinni::get(::djinni_generated::NativeBalanceRecord::fromCpp(jniEnv, c_new_balance)));
    ::djinni::jniExceptionCheck(jniEnv);
    return ::djinni::Bool::toCpp(jniEnv, jret);
}

}  // namespace djinni_generated