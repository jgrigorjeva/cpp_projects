#ifndef MATERIA_SOURCE
# define MATERIA_SOURCE

# include "AMateria.hpp"
# include <iostream>

class IMateriaSource
{
  public:
	virtual ~IMateriaSource()
	{
	}
	virtual void learnMateria(AMateria *) = 0;
	virtual AMateria *createMateria(std::string const &type) = 0;
};

class MateriaSource : public IMateriaSource
{
  private:
	AMateria *s_inventory[4];

  public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	~MateriaSource();
	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);
};

#endif