#include "ScalarConverter.hpp"
void	ScalarConverter::convert(string& s)
{
	switch (_getType(s))
	{
	case CHAR:
		{
			if (std::isprint(s[0]))
				cout << "char: '" << s[0] << "'" << endl;
			else
				cout << "char: Non displayable" << endl;
			cout << "int: " << static_cast<int>(s[0]) << endl;
			cout << "float: " << static_cast<float>(s[0]) << ".0f" << endl;
			cout << "double: " << static_cast<double>(s[0]) << ".0" << endl;
			break;
		}
	case INT:
		{
			if (std::isprint(static_cast<char>(atoi(s.c_str()))))
				cout << "char: '" << static_cast<char>(atoi(s.c_str())) << "'" << endl;
			else
				cout << "Non displayable" << endl;
			cout << "int: " << atoi(s.c_str()) << endl;
			cout << "float: " << static_cast<float>(atoi(s.c_str())) << ".0f" << endl;
			cout << "double: " << static_cast<double>(atoi(s.c_str())) << ".0" << endl;
			break;
		}
	case FLOAT:
		{
			if (std::isprint(static_cast<char>(atof(s.c_str()))))
				cout << "char: '" << static_cast<char>(atof(s.c_str())) << "'" << endl;
			else
				cout << "Non displayable" << endl;
			cout << "int: " << static_cast<int>(atof(s.c_str())) << endl;
			cout << "float: " << atof(s.c_str());
			if (atof(s.c_str()) == static_cast<int>(atof(s.c_str())))
				cout << ".0";
			cout << "f" << endl;
			cout << "double: " << static_cast<double>(strtod(s.c_str(), 0));
			if (atof(s.c_str()) == static_cast<int>(strtod(s.c_str(), 0)))
				cout << ".0";
			cout << endl;
			break;
		}
	case DOUBLE:
		{
			if (std::isprint(static_cast<char>(atof(s.c_str()))))
				cout << "char: '" << static_cast<char>(atof(s.c_str())) << "'" << endl;
			else
				cout << "Non displayable" << endl;
			cout << "int: " << static_cast<int>(atof(s.c_str())) << endl;
			cout << "float: " << atof(s.c_str());
			if (atof(s.c_str()) == static_cast<int>(atof(s.c_str())))
				cout << ".0";
			cout << "f" << endl;
			cout << "double: " << static_cast<double>(strtod(s.c_str(), 0));
			if (atof(s.c_str()) == static_cast<int>(strtod(s.c_str(), 0)))
				cout << ".0";
			cout << endl;
			break;
		}
	case NAN_INF:
		{
			cout << "char: impossible" << endl;
			cout << "int: impossible" << endl;
			cout << "float: ";
			if (s == "nan" || s == "nanf")
				cout << "nanf" << endl;
			else if (s == "+inf" || s == "+inff")
				cout << "+inff" << endl;
			else
				cout << "-inff" << endl;
			cout << "double: ";
			if (s == "nan" || s == "nanf")
				cout << "nan" << endl;
			else if (s == "+inf" || s == "+inff")
				cout << "+inf" << endl;
			else
				cout << "-inf" << endl;
			break;
		}
	default:
		throw std::invalid_argument("Invalid argument");
		break;
	}
}

ScalarType	ScalarConverter::_getType(string& value)
{
	if (value.length() == 1 && !isdigit(value[0]))
		return CHAR;
	if (value == "nan" || value == "+inf" || value == "-inf" ||
		value == "nanf" || value == "+inff" || value == "-inff")
		return NAN_INF;
	if (value.find_first_of("+-") != value.find_last_of("+-"))
		return INVALID;
	if (value.find_first_not_of("-+0123456789") == string::npos)
		return INT;
	if (value.find_first_not_of("-+0123456789.") == string::npos)
	{
		if (value.find_first_of(".") == value.find_last_of(".")
			&& isdigit(value[value.find_first_of(".") + 1])
			&& value.find_first_of(".") != 0)
			return DOUBLE;
		else
			return INVALID;
	}
	if (value.find_first_not_of("-+0123456789.f") == string::npos)
	{
		if (value.find_first_of("f") == value.find_last_of("f")
			&& value.find_first_of(".") == value.find_last_of(".")
			&& value.find_first_of("f") > value.find_first_of(".")
			&& value.find_first_of("f") - value.find_first_of(".") != 1
			&& value.find_first_of(".") != 0
			&& value.find_first_of("f") == (value.length() - 1))
			return FLOAT;
		return INVALID;
	}
	return INVALID;	
}
