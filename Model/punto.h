#ifndef PUNTO_H
#define PUNTO_H


class Punto
{
private:
  double x;
  double y;
public:
  Punto(double=0, double=0);//costruttore a 2 argomenti con valori di default
  Punto(const Punto&);
   ~Punto()=default;


  //getter
  double getX() const;
  double getY() const;
  Punto getPunto() const; //metodo che mi ritorna un oggetto punto

  //setter
  void setPunto(const Punto&);
  void setX(double);
  void setY(double);

  static double distanzaDuePunti(const Punto&, const Punto&); // dichiaro un metodo statico quando l'azione del metodo e
  // indipendente dall'oggetto d'invocazione. Questo è una specie di metodo globale.
};

#endif // PUNTO_H
