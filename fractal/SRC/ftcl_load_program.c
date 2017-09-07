///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   ftcl_load_program.c                                :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2017/06/10 20:40:57 by akrotov           #+#    #+#             */
///*   Updated: 2017/06/10 20:40:58 by akrotov          ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "fractal.h"
//
//char		*load_program_source(const char *filename)
//{
//	struct stat	statbuf;
//	FILE		*fh;
//	char		*source;
//
//	fh = fopen(filename, "r");
//	if (fh == 0)
//		return (0);
//	stat(filename, &statbuf);
//	source = (char *)malloc(statbuf.st_size + 1);
//	fread(source, statbuf.st_size, 1, fh);
//	source[statbuf.st_size] = '\0';
//	fclose(fh);
//	return (source);
//}
//
//cl_kernel	load_kernel_from_file(cl_context context, const char *filename)
//{
//	cl_program	program[1];
//	cl_kernel	kernel[1];
//	int			err;
//	char		*program_source;
//
//	program_source = load_program_source(filename);
//	program[0] = clCreateProgramWithSource(context, 1,
//	(const char**)&program_source, NULL, &err);
//	check_succeeded("Loading kernel", err);
//	err = clBuildProgram(program[0], 0, NULL, NULL, NULL, NULL);
//	check_succeeded("Building program", err);
//	kernel[0] = clCreateKernel(program[0], "render", &err);
//	err = clReleaseProgram(program[0]);
//	check_succeeded("Release program", err);
//	free(program_source);
//	program_source = NULL;
//	return (kernel[0]);
//}
