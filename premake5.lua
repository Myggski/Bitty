workspace "Bitty"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Bitty"
	location "Bitty"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "off"
		systemversion "latest"

		defines
		{
			"BITTY_PLATFORM_WINDOWS",
			"BITTY_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/BittyTesting\"")
		}

	filter "configurations:Debug"
		defines "BITTY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BITTY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BITTY_DIST"
		optimize "On"

project "BittyTesting"
	location "BittyTesting"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	nuget
	{
		"Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn:1.8.1.5"
	}

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp"
	}

	includedirs
	{
		"Bitty/vendor/spdlog/include",
		"Bitty/src"
	}

	links
	{
		"Bitty"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "off"
		systemversion "latest"

		defines
		{
			"BITTY_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BITTY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BITTY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BITTY_DIST"
		optimize "On"

postbuildcommands
{
	("{COPY} ../bin/" .. outputdir .. "/Bitty/Bitty.dll" .. " ../bin/" .. outputdir .. "/%{prj.name}")
}