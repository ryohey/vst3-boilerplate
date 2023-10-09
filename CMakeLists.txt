cmake_minimum_required(VERSION 3.14.0)
set(CMAKE_OSX_DEPLOYMENT_TARGET 10.13 CACHE STRING "")

project(MIDIOutputExample
    # This is your plug-in version number. Change it here only.
    # Version number symbols usable in C++ can be found in
    # source/version.h and ${PROJECT_BINARY_DIR}/projectversion.h.
    VERSION 1.0.0.0 
    DESCRIPTION "MIDIOutputExample VST 3 Plug-in"
)

set(vst3sdk_SOURCE_DIR ${PROJECT_SOURCE_DIR}/vst3sdk)

set(SMTG_VSTGUI_ROOT "${vst3sdk_SOURCE_DIR}")

add_subdirectory(${vst3sdk_SOURCE_DIR} ${PROJECT_BINARY_DIR}/vst3sdk)
smtg_enable_vst3_sdk()

smtg_add_vst3plugin(MIDIOutputExample
    source/version.h
    source/cids.h
    source/processor.h
    source/processor.cpp
    source/controller.h
    source/controller.cpp
    source/entry.cpp
)

#- VSTGUI Wanted ----
if(SMTG_ADD_VSTGUI)
    target_sources(MIDIOutputExample
        PRIVATE
            resource/editor.uidesc
    )
    target_link_libraries(MIDIOutputExample
        PRIVATE
            vstgui_support
    )
    smtg_target_add_plugin_resources(MIDIOutputExample
        RESOURCES
            "resource/editor.uidesc"
    )
endif(SMTG_ADD_VSTGUI)
# -------------------

smtg_target_add_plugin_snapshots (MIDIOutputExample
    RESOURCES
        resource/6B3E46C9B8F959FBB1C3E8F02691CD64_snapshot.png
        resource/6B3E46C9B8F959FBB1C3E8F02691CD64_snapshot_2.0x.png
)

target_link_libraries(MIDIOutputExample
    PRIVATE
        sdk
)

smtg_target_configure_version_file(MIDIOutputExample)

if(SMTG_MAC)
    smtg_target_set_bundle(MIDIOutputExample
        BUNDLE_IDENTIFIER com.covelline.midioutputexample
        COMPANY_NAME ""
    )
    smtg_target_set_debug_executable(MIDIOutputExample
        "/Applications/VST3PluginTestHost.app"
        "--pluginfolder;$(BUILT_PRODUCTS_DIR)"
    )
elseif(SMTG_WIN)
    target_sources(MIDIOutputExample PRIVATE 
        resource/win32resource.rc
    )
    if(MSVC)
        set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT MIDIOutputExample)

        smtg_target_set_debug_executable(MIDIOutputExample
            "$(ProgramW6432)/Steinberg/VST3PluginTestHost/VST3PluginTestHost.exe"
            "--pluginfolder \"$(OutDir)/\""
        )
    endif()
endif(SMTG_MAC)
