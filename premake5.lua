-- premake5.lua
-- generated by muhhae

workspace "App"
    configurations { "Debug", "Release" }
    platforms { "x64" }

project "interpreter"
    kind "ConsoleApp"
    language "C++"
    
    cppdialect "C++latest"

    includedirs {
        "D:/Other/Python/include",
        "D:/vcpkg/installed/x64-windows/include",
        "External/entity-component-system/include"
    }

    links {
        "D:/Other/Python/libs/python311",
    }

    targetdir "bin/%{cfg.buildcfg}"
    objdir "obj/%{cfg.buildcfg}"

    files {
        "src/**.cpp"
    }

    removefiles {
        "src/App.cpp"
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        optimize "On"


project "App"
    kind "SharedLib" --App Type
    targetextension ".pyd" --Target Extension
    language "C++" --Languange

    cppdialect "C++latest"

    includedirs {
        "D:/Other/Python/include",
        "D:/vcpkg/installed/x64-windows/include",
        "External/entity-component-system/include",
        "External/entt/include"
    }

    links {
        "D:/Other/Python/libs/python311",
    }

    targetdir "bin/%{cfg.buildcfg}" 
    objdir "obj/%{cfg.buildcfg}"

    files {
        "src/App.cpp"
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        optimize "On"
