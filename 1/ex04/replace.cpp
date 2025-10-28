/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-26 08:57:29 by bh                #+#    #+#             */
/*   Updated: 2025-10-26 08:57:29 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>

static bool	write_file(std::ofstream& out, const std::string& data)
{
	if (out.write(data.data(), static_cast<std::streamsize>(data.size())))
		return true;
	return false;
}

static std::string	read_file(std::ifstream& in)
{
	std::ostringstream	oss;

	oss << in.rdbuf();
	return oss.str();
}

static bool	open_output_file(const std::string& filename, std::ofstream& out)
{
	const std::string	path = filename + ".replace";

	out.open(path.c_str(), std::ios::out | std::ios::binary | std::ios::trunc);
	if (out)
		return true;
	std::cerr << "Error: cannot create output file: " << path << "\n";
	return false;
}

static bool	open_input_file(const char* filename, std::ifstream& in)
{
	in.open(filename, std::ios::in | std::ios::binary);
	if (in)
		return true;
	std::cerr << "Error: cannot open input file: " << filename << "\n";
	return false;
}

static void	replace(const std::string& filename, const std::string& target, const std::string& update)
{
	std::ifstream			in;
	std::ofstream			out;
	std::string				input;
	std::string				result;
	std::string::size_type	cur = 0;

	if (!open_input_file(filename.c_str(), in))
		return ;

	if (!open_output_file(filename, out))
		return ;

	input = read_file(in);

	if (target == update)
	{
		write_file(out, input);
		return ;
	}

	result.reserve(input.size());
	while (true)
	{
		std::string::size_type pos = input.find(target, cur);
		if (pos == std::string::npos)
		{
			result.append(input, cur, std::string::npos);
			break;
		}
		result.append(input, cur, pos - cur);
		result.append(update);
		cur = pos + target.size();
	}
	if (!write_file(out, result))
    	std::cerr << "Error: failed to write output\n";
}

static bool is_valid_input(int ac, char** av)
{
	if (ac != 3)
	{
		std::cerr << "Usage: <filename> <s1> <s2>\n";
		return false;
    }

	const std::string	filename = av[0];
	const std::string	s1 = av[1];

	if (filename.empty() || s1.empty())
	{
		std::cerr << "Error: filename and s1 must be non-empty\n";
		return false;
	}
	return true;
}

void	run_replace(int ac, char **av)
{
	if (is_valid_input(ac, av))
		replace(av[0], av[1], av[2]);
}
