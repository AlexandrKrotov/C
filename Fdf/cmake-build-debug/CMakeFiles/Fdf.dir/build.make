# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nfs/2016/a/akrotov/ClionProjects/Fdf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/2016/a/akrotov/ClionProjects/Fdf/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Fdf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Fdf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Fdf.dir/flags.make

CMakeFiles/Fdf.dir/main.c.o: CMakeFiles/Fdf.dir/flags.make
CMakeFiles/Fdf.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/a/akrotov/ClionProjects/Fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Fdf.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fdf.dir/main.c.o   -c /nfs/2016/a/akrotov/ClionProjects/Fdf/main.c

CMakeFiles/Fdf.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fdf.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/a/akrotov/ClionProjects/Fdf/main.c > CMakeFiles/Fdf.dir/main.c.i

CMakeFiles/Fdf.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fdf.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/a/akrotov/ClionProjects/Fdf/main.c -o CMakeFiles/Fdf.dir/main.c.s

CMakeFiles/Fdf.dir/main.c.o.requires:

.PHONY : CMakeFiles/Fdf.dir/main.c.o.requires

CMakeFiles/Fdf.dir/main.c.o.provides: CMakeFiles/Fdf.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Fdf.dir/build.make CMakeFiles/Fdf.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Fdf.dir/main.c.o.provides

CMakeFiles/Fdf.dir/main.c.o.provides.build: CMakeFiles/Fdf.dir/main.c.o


CMakeFiles/Fdf.dir/ft_draw_line.c.o: CMakeFiles/Fdf.dir/flags.make
CMakeFiles/Fdf.dir/ft_draw_line.c.o: ../ft_draw_line.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/a/akrotov/ClionProjects/Fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Fdf.dir/ft_draw_line.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fdf.dir/ft_draw_line.c.o   -c /nfs/2016/a/akrotov/ClionProjects/Fdf/ft_draw_line.c

CMakeFiles/Fdf.dir/ft_draw_line.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fdf.dir/ft_draw_line.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/a/akrotov/ClionProjects/Fdf/ft_draw_line.c > CMakeFiles/Fdf.dir/ft_draw_line.c.i

CMakeFiles/Fdf.dir/ft_draw_line.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fdf.dir/ft_draw_line.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/a/akrotov/ClionProjects/Fdf/ft_draw_line.c -o CMakeFiles/Fdf.dir/ft_draw_line.c.s

CMakeFiles/Fdf.dir/ft_draw_line.c.o.requires:

.PHONY : CMakeFiles/Fdf.dir/ft_draw_line.c.o.requires

CMakeFiles/Fdf.dir/ft_draw_line.c.o.provides: CMakeFiles/Fdf.dir/ft_draw_line.c.o.requires
	$(MAKE) -f CMakeFiles/Fdf.dir/build.make CMakeFiles/Fdf.dir/ft_draw_line.c.o.provides.build
.PHONY : CMakeFiles/Fdf.dir/ft_draw_line.c.o.provides

CMakeFiles/Fdf.dir/ft_draw_line.c.o.provides.build: CMakeFiles/Fdf.dir/ft_draw_line.c.o


CMakeFiles/Fdf.dir/ft_parser.c.o: CMakeFiles/Fdf.dir/flags.make
CMakeFiles/Fdf.dir/ft_parser.c.o: ../ft_parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/a/akrotov/ClionProjects/Fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Fdf.dir/ft_parser.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fdf.dir/ft_parser.c.o   -c /nfs/2016/a/akrotov/ClionProjects/Fdf/ft_parser.c

CMakeFiles/Fdf.dir/ft_parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fdf.dir/ft_parser.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/a/akrotov/ClionProjects/Fdf/ft_parser.c > CMakeFiles/Fdf.dir/ft_parser.c.i

CMakeFiles/Fdf.dir/ft_parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fdf.dir/ft_parser.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/a/akrotov/ClionProjects/Fdf/ft_parser.c -o CMakeFiles/Fdf.dir/ft_parser.c.s

CMakeFiles/Fdf.dir/ft_parser.c.o.requires:

.PHONY : CMakeFiles/Fdf.dir/ft_parser.c.o.requires

CMakeFiles/Fdf.dir/ft_parser.c.o.provides: CMakeFiles/Fdf.dir/ft_parser.c.o.requires
	$(MAKE) -f CMakeFiles/Fdf.dir/build.make CMakeFiles/Fdf.dir/ft_parser.c.o.provides.build
.PHONY : CMakeFiles/Fdf.dir/ft_parser.c.o.provides

CMakeFiles/Fdf.dir/ft_parser.c.o.provides.build: CMakeFiles/Fdf.dir/ft_parser.c.o


CMakeFiles/Fdf.dir/libft/get_next_line.c.o: CMakeFiles/Fdf.dir/flags.make
CMakeFiles/Fdf.dir/libft/get_next_line.c.o: ../libft/get_next_line.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/a/akrotov/ClionProjects/Fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Fdf.dir/libft/get_next_line.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fdf.dir/libft/get_next_line.c.o   -c /nfs/2016/a/akrotov/ClionProjects/Fdf/libft/get_next_line.c

CMakeFiles/Fdf.dir/libft/get_next_line.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fdf.dir/libft/get_next_line.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/a/akrotov/ClionProjects/Fdf/libft/get_next_line.c > CMakeFiles/Fdf.dir/libft/get_next_line.c.i

CMakeFiles/Fdf.dir/libft/get_next_line.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fdf.dir/libft/get_next_line.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/a/akrotov/ClionProjects/Fdf/libft/get_next_line.c -o CMakeFiles/Fdf.dir/libft/get_next_line.c.s

CMakeFiles/Fdf.dir/libft/get_next_line.c.o.requires:

.PHONY : CMakeFiles/Fdf.dir/libft/get_next_line.c.o.requires

CMakeFiles/Fdf.dir/libft/get_next_line.c.o.provides: CMakeFiles/Fdf.dir/libft/get_next_line.c.o.requires
	$(MAKE) -f CMakeFiles/Fdf.dir/build.make CMakeFiles/Fdf.dir/libft/get_next_line.c.o.provides.build
.PHONY : CMakeFiles/Fdf.dir/libft/get_next_line.c.o.provides

CMakeFiles/Fdf.dir/libft/get_next_line.c.o.provides.build: CMakeFiles/Fdf.dir/libft/get_next_line.c.o


CMakeFiles/Fdf.dir/ft_hook.c.o: CMakeFiles/Fdf.dir/flags.make
CMakeFiles/Fdf.dir/ft_hook.c.o: ../ft_hook.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/a/akrotov/ClionProjects/Fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Fdf.dir/ft_hook.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fdf.dir/ft_hook.c.o   -c /nfs/2016/a/akrotov/ClionProjects/Fdf/ft_hook.c

CMakeFiles/Fdf.dir/ft_hook.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fdf.dir/ft_hook.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/a/akrotov/ClionProjects/Fdf/ft_hook.c > CMakeFiles/Fdf.dir/ft_hook.c.i

CMakeFiles/Fdf.dir/ft_hook.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fdf.dir/ft_hook.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/a/akrotov/ClionProjects/Fdf/ft_hook.c -o CMakeFiles/Fdf.dir/ft_hook.c.s

CMakeFiles/Fdf.dir/ft_hook.c.o.requires:

.PHONY : CMakeFiles/Fdf.dir/ft_hook.c.o.requires

CMakeFiles/Fdf.dir/ft_hook.c.o.provides: CMakeFiles/Fdf.dir/ft_hook.c.o.requires
	$(MAKE) -f CMakeFiles/Fdf.dir/build.make CMakeFiles/Fdf.dir/ft_hook.c.o.provides.build
.PHONY : CMakeFiles/Fdf.dir/ft_hook.c.o.provides

CMakeFiles/Fdf.dir/ft_hook.c.o.provides.build: CMakeFiles/Fdf.dir/ft_hook.c.o


CMakeFiles/Fdf.dir/ft_error.c.o: CMakeFiles/Fdf.dir/flags.make
CMakeFiles/Fdf.dir/ft_error.c.o: ../ft_error.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/a/akrotov/ClionProjects/Fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Fdf.dir/ft_error.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fdf.dir/ft_error.c.o   -c /nfs/2016/a/akrotov/ClionProjects/Fdf/ft_error.c

CMakeFiles/Fdf.dir/ft_error.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fdf.dir/ft_error.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/a/akrotov/ClionProjects/Fdf/ft_error.c > CMakeFiles/Fdf.dir/ft_error.c.i

CMakeFiles/Fdf.dir/ft_error.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fdf.dir/ft_error.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/a/akrotov/ClionProjects/Fdf/ft_error.c -o CMakeFiles/Fdf.dir/ft_error.c.s

CMakeFiles/Fdf.dir/ft_error.c.o.requires:

.PHONY : CMakeFiles/Fdf.dir/ft_error.c.o.requires

CMakeFiles/Fdf.dir/ft_error.c.o.provides: CMakeFiles/Fdf.dir/ft_error.c.o.requires
	$(MAKE) -f CMakeFiles/Fdf.dir/build.make CMakeFiles/Fdf.dir/ft_error.c.o.provides.build
.PHONY : CMakeFiles/Fdf.dir/ft_error.c.o.provides

CMakeFiles/Fdf.dir/ft_error.c.o.provides.build: CMakeFiles/Fdf.dir/ft_error.c.o


CMakeFiles/Fdf.dir/axis_rotation.c.o: CMakeFiles/Fdf.dir/flags.make
CMakeFiles/Fdf.dir/axis_rotation.c.o: ../axis_rotation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/a/akrotov/ClionProjects/Fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Fdf.dir/axis_rotation.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fdf.dir/axis_rotation.c.o   -c /nfs/2016/a/akrotov/ClionProjects/Fdf/axis_rotation.c

CMakeFiles/Fdf.dir/axis_rotation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fdf.dir/axis_rotation.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/a/akrotov/ClionProjects/Fdf/axis_rotation.c > CMakeFiles/Fdf.dir/axis_rotation.c.i

CMakeFiles/Fdf.dir/axis_rotation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fdf.dir/axis_rotation.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/a/akrotov/ClionProjects/Fdf/axis_rotation.c -o CMakeFiles/Fdf.dir/axis_rotation.c.s

CMakeFiles/Fdf.dir/axis_rotation.c.o.requires:

.PHONY : CMakeFiles/Fdf.dir/axis_rotation.c.o.requires

CMakeFiles/Fdf.dir/axis_rotation.c.o.provides: CMakeFiles/Fdf.dir/axis_rotation.c.o.requires
	$(MAKE) -f CMakeFiles/Fdf.dir/build.make CMakeFiles/Fdf.dir/axis_rotation.c.o.provides.build
.PHONY : CMakeFiles/Fdf.dir/axis_rotation.c.o.provides

CMakeFiles/Fdf.dir/axis_rotation.c.o.provides.build: CMakeFiles/Fdf.dir/axis_rotation.c.o


CMakeFiles/Fdf.dir/mulst_scale_shift.c.o: CMakeFiles/Fdf.dir/flags.make
CMakeFiles/Fdf.dir/mulst_scale_shift.c.o: ../mulst_scale_shift.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/a/akrotov/ClionProjects/Fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/Fdf.dir/mulst_scale_shift.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fdf.dir/mulst_scale_shift.c.o   -c /nfs/2016/a/akrotov/ClionProjects/Fdf/mulst_scale_shift.c

CMakeFiles/Fdf.dir/mulst_scale_shift.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fdf.dir/mulst_scale_shift.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/a/akrotov/ClionProjects/Fdf/mulst_scale_shift.c > CMakeFiles/Fdf.dir/mulst_scale_shift.c.i

CMakeFiles/Fdf.dir/mulst_scale_shift.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fdf.dir/mulst_scale_shift.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/a/akrotov/ClionProjects/Fdf/mulst_scale_shift.c -o CMakeFiles/Fdf.dir/mulst_scale_shift.c.s

CMakeFiles/Fdf.dir/mulst_scale_shift.c.o.requires:

.PHONY : CMakeFiles/Fdf.dir/mulst_scale_shift.c.o.requires

CMakeFiles/Fdf.dir/mulst_scale_shift.c.o.provides: CMakeFiles/Fdf.dir/mulst_scale_shift.c.o.requires
	$(MAKE) -f CMakeFiles/Fdf.dir/build.make CMakeFiles/Fdf.dir/mulst_scale_shift.c.o.provides.build
.PHONY : CMakeFiles/Fdf.dir/mulst_scale_shift.c.o.provides

CMakeFiles/Fdf.dir/mulst_scale_shift.c.o.provides.build: CMakeFiles/Fdf.dir/mulst_scale_shift.c.o


CMakeFiles/Fdf.dir/all_calc.c.o: CMakeFiles/Fdf.dir/flags.make
CMakeFiles/Fdf.dir/all_calc.c.o: ../all_calc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/a/akrotov/ClionProjects/Fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/Fdf.dir/all_calc.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fdf.dir/all_calc.c.o   -c /nfs/2016/a/akrotov/ClionProjects/Fdf/all_calc.c

CMakeFiles/Fdf.dir/all_calc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fdf.dir/all_calc.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/a/akrotov/ClionProjects/Fdf/all_calc.c > CMakeFiles/Fdf.dir/all_calc.c.i

CMakeFiles/Fdf.dir/all_calc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fdf.dir/all_calc.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/a/akrotov/ClionProjects/Fdf/all_calc.c -o CMakeFiles/Fdf.dir/all_calc.c.s

CMakeFiles/Fdf.dir/all_calc.c.o.requires:

.PHONY : CMakeFiles/Fdf.dir/all_calc.c.o.requires

CMakeFiles/Fdf.dir/all_calc.c.o.provides: CMakeFiles/Fdf.dir/all_calc.c.o.requires
	$(MAKE) -f CMakeFiles/Fdf.dir/build.make CMakeFiles/Fdf.dir/all_calc.c.o.provides.build
.PHONY : CMakeFiles/Fdf.dir/all_calc.c.o.provides

CMakeFiles/Fdf.dir/all_calc.c.o.provides.build: CMakeFiles/Fdf.dir/all_calc.c.o


CMakeFiles/Fdf.dir/all_free.c.o: CMakeFiles/Fdf.dir/flags.make
CMakeFiles/Fdf.dir/all_free.c.o: ../all_free.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/a/akrotov/ClionProjects/Fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/Fdf.dir/all_free.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fdf.dir/all_free.c.o   -c /nfs/2016/a/akrotov/ClionProjects/Fdf/all_free.c

CMakeFiles/Fdf.dir/all_free.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fdf.dir/all_free.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/a/akrotov/ClionProjects/Fdf/all_free.c > CMakeFiles/Fdf.dir/all_free.c.i

CMakeFiles/Fdf.dir/all_free.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fdf.dir/all_free.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/a/akrotov/ClionProjects/Fdf/all_free.c -o CMakeFiles/Fdf.dir/all_free.c.s

CMakeFiles/Fdf.dir/all_free.c.o.requires:

.PHONY : CMakeFiles/Fdf.dir/all_free.c.o.requires

CMakeFiles/Fdf.dir/all_free.c.o.provides: CMakeFiles/Fdf.dir/all_free.c.o.requires
	$(MAKE) -f CMakeFiles/Fdf.dir/build.make CMakeFiles/Fdf.dir/all_free.c.o.provides.build
.PHONY : CMakeFiles/Fdf.dir/all_free.c.o.provides

CMakeFiles/Fdf.dir/all_free.c.o.provides.build: CMakeFiles/Fdf.dir/all_free.c.o


CMakeFiles/Fdf.dir/all_color.c.o: CMakeFiles/Fdf.dir/flags.make
CMakeFiles/Fdf.dir/all_color.c.o: ../all_color.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/a/akrotov/ClionProjects/Fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/Fdf.dir/all_color.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fdf.dir/all_color.c.o   -c /nfs/2016/a/akrotov/ClionProjects/Fdf/all_color.c

CMakeFiles/Fdf.dir/all_color.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fdf.dir/all_color.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/a/akrotov/ClionProjects/Fdf/all_color.c > CMakeFiles/Fdf.dir/all_color.c.i

CMakeFiles/Fdf.dir/all_color.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fdf.dir/all_color.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/a/akrotov/ClionProjects/Fdf/all_color.c -o CMakeFiles/Fdf.dir/all_color.c.s

CMakeFiles/Fdf.dir/all_color.c.o.requires:

.PHONY : CMakeFiles/Fdf.dir/all_color.c.o.requires

CMakeFiles/Fdf.dir/all_color.c.o.provides: CMakeFiles/Fdf.dir/all_color.c.o.requires
	$(MAKE) -f CMakeFiles/Fdf.dir/build.make CMakeFiles/Fdf.dir/all_color.c.o.provides.build
.PHONY : CMakeFiles/Fdf.dir/all_color.c.o.provides

CMakeFiles/Fdf.dir/all_color.c.o.provides.build: CMakeFiles/Fdf.dir/all_color.c.o


CMakeFiles/Fdf.dir/bonus_ft.c.o: CMakeFiles/Fdf.dir/flags.make
CMakeFiles/Fdf.dir/bonus_ft.c.o: ../bonus_ft.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/a/akrotov/ClionProjects/Fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/Fdf.dir/bonus_ft.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fdf.dir/bonus_ft.c.o   -c /nfs/2016/a/akrotov/ClionProjects/Fdf/bonus_ft.c

CMakeFiles/Fdf.dir/bonus_ft.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fdf.dir/bonus_ft.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/a/akrotov/ClionProjects/Fdf/bonus_ft.c > CMakeFiles/Fdf.dir/bonus_ft.c.i

CMakeFiles/Fdf.dir/bonus_ft.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fdf.dir/bonus_ft.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/a/akrotov/ClionProjects/Fdf/bonus_ft.c -o CMakeFiles/Fdf.dir/bonus_ft.c.s

CMakeFiles/Fdf.dir/bonus_ft.c.o.requires:

.PHONY : CMakeFiles/Fdf.dir/bonus_ft.c.o.requires

CMakeFiles/Fdf.dir/bonus_ft.c.o.provides: CMakeFiles/Fdf.dir/bonus_ft.c.o.requires
	$(MAKE) -f CMakeFiles/Fdf.dir/build.make CMakeFiles/Fdf.dir/bonus_ft.c.o.provides.build
.PHONY : CMakeFiles/Fdf.dir/bonus_ft.c.o.provides

CMakeFiles/Fdf.dir/bonus_ft.c.o.provides.build: CMakeFiles/Fdf.dir/bonus_ft.c.o


CMakeFiles/Fdf.dir/drow_map.c.o: CMakeFiles/Fdf.dir/flags.make
CMakeFiles/Fdf.dir/drow_map.c.o: ../drow_map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/a/akrotov/ClionProjects/Fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/Fdf.dir/drow_map.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fdf.dir/drow_map.c.o   -c /nfs/2016/a/akrotov/ClionProjects/Fdf/drow_map.c

CMakeFiles/Fdf.dir/drow_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fdf.dir/drow_map.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/a/akrotov/ClionProjects/Fdf/drow_map.c > CMakeFiles/Fdf.dir/drow_map.c.i

CMakeFiles/Fdf.dir/drow_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fdf.dir/drow_map.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/a/akrotov/ClionProjects/Fdf/drow_map.c -o CMakeFiles/Fdf.dir/drow_map.c.s

CMakeFiles/Fdf.dir/drow_map.c.o.requires:

.PHONY : CMakeFiles/Fdf.dir/drow_map.c.o.requires

CMakeFiles/Fdf.dir/drow_map.c.o.provides: CMakeFiles/Fdf.dir/drow_map.c.o.requires
	$(MAKE) -f CMakeFiles/Fdf.dir/build.make CMakeFiles/Fdf.dir/drow_map.c.o.provides.build
.PHONY : CMakeFiles/Fdf.dir/drow_map.c.o.provides

CMakeFiles/Fdf.dir/drow_map.c.o.provides.build: CMakeFiles/Fdf.dir/drow_map.c.o


CMakeFiles/Fdf.dir/ft_mouse_hook.c.o: CMakeFiles/Fdf.dir/flags.make
CMakeFiles/Fdf.dir/ft_mouse_hook.c.o: ../ft_mouse_hook.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/a/akrotov/ClionProjects/Fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/Fdf.dir/ft_mouse_hook.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fdf.dir/ft_mouse_hook.c.o   -c /nfs/2016/a/akrotov/ClionProjects/Fdf/ft_mouse_hook.c

CMakeFiles/Fdf.dir/ft_mouse_hook.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fdf.dir/ft_mouse_hook.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/a/akrotov/ClionProjects/Fdf/ft_mouse_hook.c > CMakeFiles/Fdf.dir/ft_mouse_hook.c.i

CMakeFiles/Fdf.dir/ft_mouse_hook.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fdf.dir/ft_mouse_hook.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/a/akrotov/ClionProjects/Fdf/ft_mouse_hook.c -o CMakeFiles/Fdf.dir/ft_mouse_hook.c.s

CMakeFiles/Fdf.dir/ft_mouse_hook.c.o.requires:

.PHONY : CMakeFiles/Fdf.dir/ft_mouse_hook.c.o.requires

CMakeFiles/Fdf.dir/ft_mouse_hook.c.o.provides: CMakeFiles/Fdf.dir/ft_mouse_hook.c.o.requires
	$(MAKE) -f CMakeFiles/Fdf.dir/build.make CMakeFiles/Fdf.dir/ft_mouse_hook.c.o.provides.build
.PHONY : CMakeFiles/Fdf.dir/ft_mouse_hook.c.o.provides

CMakeFiles/Fdf.dir/ft_mouse_hook.c.o.provides.build: CMakeFiles/Fdf.dir/ft_mouse_hook.c.o


# Object files for target Fdf
Fdf_OBJECTS = \
"CMakeFiles/Fdf.dir/main.c.o" \
"CMakeFiles/Fdf.dir/ft_draw_line.c.o" \
"CMakeFiles/Fdf.dir/ft_parser.c.o" \
"CMakeFiles/Fdf.dir/libft/get_next_line.c.o" \
"CMakeFiles/Fdf.dir/ft_hook.c.o" \
"CMakeFiles/Fdf.dir/ft_error.c.o" \
"CMakeFiles/Fdf.dir/axis_rotation.c.o" \
"CMakeFiles/Fdf.dir/mulst_scale_shift.c.o" \
"CMakeFiles/Fdf.dir/all_calc.c.o" \
"CMakeFiles/Fdf.dir/all_free.c.o" \
"CMakeFiles/Fdf.dir/all_color.c.o" \
"CMakeFiles/Fdf.dir/bonus_ft.c.o" \
"CMakeFiles/Fdf.dir/drow_map.c.o" \
"CMakeFiles/Fdf.dir/ft_mouse_hook.c.o"

# External object files for target Fdf
Fdf_EXTERNAL_OBJECTS =

Fdf: CMakeFiles/Fdf.dir/main.c.o
Fdf: CMakeFiles/Fdf.dir/ft_draw_line.c.o
Fdf: CMakeFiles/Fdf.dir/ft_parser.c.o
Fdf: CMakeFiles/Fdf.dir/libft/get_next_line.c.o
Fdf: CMakeFiles/Fdf.dir/ft_hook.c.o
Fdf: CMakeFiles/Fdf.dir/ft_error.c.o
Fdf: CMakeFiles/Fdf.dir/axis_rotation.c.o
Fdf: CMakeFiles/Fdf.dir/mulst_scale_shift.c.o
Fdf: CMakeFiles/Fdf.dir/all_calc.c.o
Fdf: CMakeFiles/Fdf.dir/all_free.c.o
Fdf: CMakeFiles/Fdf.dir/all_color.c.o
Fdf: CMakeFiles/Fdf.dir/bonus_ft.c.o
Fdf: CMakeFiles/Fdf.dir/drow_map.c.o
Fdf: CMakeFiles/Fdf.dir/ft_mouse_hook.c.o
Fdf: CMakeFiles/Fdf.dir/build.make
Fdf: ../libft/libft.a
Fdf: CMakeFiles/Fdf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/2016/a/akrotov/ClionProjects/Fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking C executable Fdf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Fdf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Fdf.dir/build: Fdf

.PHONY : CMakeFiles/Fdf.dir/build

CMakeFiles/Fdf.dir/requires: CMakeFiles/Fdf.dir/main.c.o.requires
CMakeFiles/Fdf.dir/requires: CMakeFiles/Fdf.dir/ft_draw_line.c.o.requires
CMakeFiles/Fdf.dir/requires: CMakeFiles/Fdf.dir/ft_parser.c.o.requires
CMakeFiles/Fdf.dir/requires: CMakeFiles/Fdf.dir/libft/get_next_line.c.o.requires
CMakeFiles/Fdf.dir/requires: CMakeFiles/Fdf.dir/ft_hook.c.o.requires
CMakeFiles/Fdf.dir/requires: CMakeFiles/Fdf.dir/ft_error.c.o.requires
CMakeFiles/Fdf.dir/requires: CMakeFiles/Fdf.dir/axis_rotation.c.o.requires
CMakeFiles/Fdf.dir/requires: CMakeFiles/Fdf.dir/mulst_scale_shift.c.o.requires
CMakeFiles/Fdf.dir/requires: CMakeFiles/Fdf.dir/all_calc.c.o.requires
CMakeFiles/Fdf.dir/requires: CMakeFiles/Fdf.dir/all_free.c.o.requires
CMakeFiles/Fdf.dir/requires: CMakeFiles/Fdf.dir/all_color.c.o.requires
CMakeFiles/Fdf.dir/requires: CMakeFiles/Fdf.dir/bonus_ft.c.o.requires
CMakeFiles/Fdf.dir/requires: CMakeFiles/Fdf.dir/drow_map.c.o.requires
CMakeFiles/Fdf.dir/requires: CMakeFiles/Fdf.dir/ft_mouse_hook.c.o.requires

.PHONY : CMakeFiles/Fdf.dir/requires

CMakeFiles/Fdf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Fdf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Fdf.dir/clean

CMakeFiles/Fdf.dir/depend:
	cd /nfs/2016/a/akrotov/ClionProjects/Fdf/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/2016/a/akrotov/ClionProjects/Fdf /nfs/2016/a/akrotov/ClionProjects/Fdf /nfs/2016/a/akrotov/ClionProjects/Fdf/cmake-build-debug /nfs/2016/a/akrotov/ClionProjects/Fdf/cmake-build-debug /nfs/2016/a/akrotov/ClionProjects/Fdf/cmake-build-debug/CMakeFiles/Fdf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Fdf.dir/depend
