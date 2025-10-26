/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:55:29 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/16 14:05:11 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	run_replace(int ac, char **av);

int	main(int ac, char **av)
{
	run_replace(ac - 1, av + 1);
	return (0);
}



// void replace(const std::string& filename, const std::string& target, const std::string& update)
// {
//     // Валидация: пустой шаблон запрещён
//     if (target.empty()) {
//         std::cerr << "Error: s1 (target) must be non-empty\n";
//         return;
//     }

//     // Открываем входной файл (двойной режим не обязателен, но безопасен кроссплатформенно)
//     std::ifstream in(filename.c_str(), std::ios::in | std::ios::binary);
//     if (!in) {
//         std::cerr << "Error: cannot open input file: " << filename << "\n";
//         return;
//     }

//     // Читаем весь файл в строку
//     std::ostringstream oss;
//     oss << in.rdbuf();
//     std::string input = oss.str();
//     in.close();

//     // Если s1 == s2 — просто копируем
//     if (target == update) {
//         std::ofstream out((filename + ".replace").c_str(), std::ios::out | std::ios::binary);
//         if (!out) {
//             std::cerr << "Error: cannot create output file: " << filename << ".replace\n";
//             return;
//         }
//         out.write(input.data(), static_cast<std::streamsize>(input.size()));
//         return;
//     }

//     // Замена без std::string::replace
//     std::string result;
//     result.reserve(input.size()); // грубая оценка

//     std::string::size_type cur = 0;
//     while (true) {
//         std::string::size_type pos = input.find(target, cur);
//         if (pos == std::string::npos) {
//             result.append(input, cur, std::string::npos);
//             break;
//         }
//         result.append(input, cur, pos - cur);
//         result.append(update);
//         cur = pos + target.size();
//     }

//     // Пишем результат
//     std::ofstream out((filename + ".replace").c_str(), std::ios::out | std::ios::binary);
//     if (!out) {
//         std::cerr << "Error: cannot create output file: " << filename << ".replace\n";
//         return;
//     }
//     out.write(result.data(), static_cast<std::streamsize>(result.size()));
// }

// bool is_valid_input(int ac, char** av)
// {
//     if (ac != 3) {
//         std::cerr << "Usage: <filename> <s1> <s2>\n";
//         return false;
//     }
//     const std::string filename = av[0];
//     const std::string s1 = av[1];
//     // s2 (av[2]) может быть пустым — разрешено
//     if (filename.empty() || s1.empty()) {
//         std::cerr << "Error: filename and s1 must be non-empty\n";
//         return false;
//     }
//     return true;
// }

// void run_replace(int ac, char** av)
// {
//     if (is_valid_input(ac, av)) {
//         replace(av[0], av[1], av[2]);
//     }
// }
