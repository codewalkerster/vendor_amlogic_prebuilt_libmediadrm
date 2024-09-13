package youtube_service
import (
    "fmt"
    "android/soong/android"
    "android/soong/cc"
    "github.com/google/blueprint/proptools"
    "android/soong/vendor/amlogic/common/prebuilt/libmediadrm/common"
)
func init() {
    android.RegisterModuleType("libyoutubeplugin_aidl_go_defaults",
                                      libyoutubeplugin_aidl_DefaultsFactory)
    android.RegisterModuleType("youtube_service_go_defaults",
                                      youtube_service_DefaultsFactory)
}

func libyoutubeplugin_aidl_DefaultsFactory() (android.Module) {
    module := cc.DefaultsFactory()
    android.AddLoadHook(module, func(ctx android.LoadHookContext) {
        var props common.Props
        info := common.Information{
            FileString: "libyoutubeplugin_aidl.so",
            SrcPath: "vendor/amlogic/common/youtube_sign",
            System: false,
            MultiArch: true,
        }
        props.Enabled = proptools.BoolPtr(true)
        common.SetProps(ctx, &props, info)
        p := &props
        ctx.AppendProperties(p)
    })
    return module
}

func youtube_service_DefaultsFactory() (android.Module) {
    module := cc.DefaultsFactory()
    android.AddLoadHook(module, func(ctx android.LoadHookContext) {
        var props common.Props
        info := common.Information{
            FileString: "android.hardware.drm-service.youtube",
            SrcPath: "vendor/amlogic/common/youtube_sign",
            System: false,
            MultiArch: true,
        }
        sdkVersion := ctx.Config().PlatformSdkVersion()
        props.Enabled = proptools.BoolPtr(true)
        if (sdkVersion.FinalOrFutureInt() < 34) {
            props.Enabled = proptools.BoolPtr(false)
        }
        common.SetProps(ctx, &props, info)
        p := &props
        fmt.Println("youtube p.Arch.Arm.Srcs", p.Arch.Arm.Srcs)
        ctx.AppendProperties(p)
    })
    return module
}
