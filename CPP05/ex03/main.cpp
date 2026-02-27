#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));

    Intern someRandomIntern;
    AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm *scf = someRandomIntern.makeForm("shrubbery creation", "home");
    AForm *ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    AForm *bad = someRandomIntern.makeForm("coffee making", "Office");

    Bureaucrat boss("Boss", 1);
    if (rrf) { boss.signForm(*rrf); boss.executeForm(*rrf); }
    if (scf) { boss.signForm(*scf); boss.executeForm(*scf); }
    if (ppf) { boss.signForm(*ppf); boss.executeForm(*ppf); }
    (void)bad;
    delete rrf;
    delete scf;
    delete ppf;
    delete bad;
}
