package collections

object mapFilter {

  def main(args: Array[String]): Unit = {

    var ll = List(3, 4, 5)
    
    // lista dei doppi
    def doppio(x: Int) = 2*x

    println(ll.map(doppio))

    var nomi = List("pippo", "giovanni", "Piero")
    
    // lista delle lunghezze
    def slength = (x: String) => x.length()
    
    var nl = nomi.map(slength)
    nomi.map(x => x.length())
    println(nomi)
    println(nl)
    
    // lunghezza massima: applica reduce su nl
    def max = (x: Int, y: Int) => if (x > y) x else y

    println(nomi.map(slength).reduceLeft(max))

    // filter, numeri pari
    def pari = (x: Int) => (x % 2 == 0)
    println(ll.filter(pari))

    // Data una lista di nomi
    // Restituisci il nome pi� breve che inizia con la lettera 'a'
    // > Usa filter e reduce
    var nj = List("angelo", "alessandro", "paolo")
    print(
      nj.filter {
        s => s.startsWith("a")
      }.reduceLeft {
        (a: String, b: String) => if (a.length() > b.length()) b else a;
      })

  }

}