%define vendor sony

%define rpm_vendor qualcomm

%define dhd_path dhd

%define droid_target_aarch64 1

%define have_custom_img_boot 1
%define have_custom_img_recovery 1

%define enable_dtbo_update 1
%define enable_vendor_boot_update 1

# want adreno quirks is required for browser at least, and other subtle issues
%define android_config \
#define WANT_ADRENO_QUIRKS 1\
%{nil}

# On Android 8+ the system partition is (intended to be) mounted on /.
%define makefstab_skip_entries / /product /system /system_ext /vendor
Requires: droid-system

%define pre_actions /bin/sh setup-sources.sh

%define droid_src_build 1

%define straggler_files \
/bugreports\
/cache\
/d\
/persist\
/sdcard\
%{nil}

BuildRequires:  python3-base

Source99: droid-hal-common.inc
