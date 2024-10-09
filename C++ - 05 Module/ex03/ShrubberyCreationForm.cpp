#include "ShrubberyCreationForm.hpp"



ShrubberyCreationForm::ShrubberyCreationForm(void)
: AForm("ShrubberyCreationForm", 72, 45, "default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target)
: AForm("ShrubberyCreationForm", 72, 45, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
{
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw std::logic_error(this->getName() + " Form not signed");
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::ofstream file((this->getTarget() + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("The File Failed to open");
    file << "              _{\\ _{\\{\\/}/}/}__\n"
            "             {/{/\\}{/{/\\}(\\}{/\\} _\n"
            "            {/{/\\}{/{/\\}(_)/}{/{/\\}  _\n"
            "         {\\{/(/}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n"
            "        {/{/(_)/}{\\{/)/}{\\(_){/}/}/}/}\n"
            "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n"
            "      {/{/{\\{\\{(/}{\\{\\/}/}{\\}(_){\\/}\\}\n"
            "      _{\\{/{\\{/(_)/}/}{/{/{/\\}\\})\\}{/\\}\n"
            "     {/{/{\\{(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n"
            "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n"
            "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n"
            "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{(/}/}\\}/}\n"
            "       {/{\\{\\/}(_){\\{\\{(/}/}{\\(_)/}/}\\}\n"
            "         {/(/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n"
            "          (_){/{\\/}{\\{\\/}/}{\\{)/}/}(_)\n"
            "            {/{/{\\{\\/}{/{\\{\\{(_)/}\n"
            "             {/{\\{\\{\\/}/}{\\{\\\\}/}\n"
            "              {){/ {\\/}{\\/} \\}\\}\n"
            "              (_)  \\.-'.-/\n"
            "          __...--- |'-.-'| --...__\n"
            "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n"
            " -\"    ' .  . '    |.'-._| '  . .  '   \n"
            " .  '-  '    .--'  | '-.'|    .  '  . '\n"
            "          ' ..     |'-_.-|\n"
            "  .  '  .       _.-|-._ -|-._  .  '  .\n"
            "              .'   |'- .-|   '.\n"
            "  ..-'   ' .  '.   `-._.-'   .'  '  - .\n"
            "   .-' '        '-._______.-'     '  .\n"
            "        .      ~,\n"
            "    .       .   |\\   .    ' '-.\n";
	file.close();
}
