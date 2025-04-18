-- for change mode, use 'xmake f -m debug'
-- or 'xmake f -m release'
add_rules("mode.debug", "mode.release")
add_requires("wxwidgets 3.x")

target("PandaTodo")
    set_kind("binary")
    add_files("src/*.cpp")
    add_includedirs("src")
    add_packages("wxwidgets")