workspace "Lune"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Lune/vendor/GLFW/include"
IncludeDir["Glad"] = "Lune/vendor/Glad/include"
IncludeDir["ImGui"] = "Lune/vendor/imgui"
IncludeDir["glm"] = "Lune/vendor/glm"

include "Lune/vendor/GLFW"
include "Lune/vendor/Glad"
include "Lune/vendor/imgui"

project "Lune"
	location "Lune"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "lnpch.h"
	pchsource "Lune/src/lnpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"LN_PLATFORM_WINDOWS",
			"LN_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "LN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "LN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "LN_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Lune/vendor/spdlog/include",
		"Lune/src",
		"%{IncludeDir.glm}",
		"Lune/vendor"
	}

	links
	{
		"Lune"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"LN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "LN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "LN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "LN_DIST"
		runtime "Release"
		optimize "on"
