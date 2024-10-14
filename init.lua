local hotwire_lib = grbc_library(LibraryConfig.new({
	name = "libhotwire",
	language_type = LanguageType.C,

	files = {
		grbc_file("src/dlopen.c")
	},

	lib_type = LibraryType.Static,
	requirements = {},
	compile_flags = {},
	linker_flags = {},
	include_dirs = {
		grbc_file("src")
	},

	package_config = PackageConfig.new({
		name = "libhotwire",
		libraries = {},
		include_dirs = {
			grbc_file("src")
		},
		compile_flags = {},
		linker_flags = {}
	})
}))
