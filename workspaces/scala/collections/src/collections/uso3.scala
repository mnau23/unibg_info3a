package collections

object uso3 {

  def main(args: Array[String]): Unit = {

    var l = List(1, 2, 4)
    
    // Imperativo
    var sum = 0;
    for (n <- l) {
      sum += n
    }
    
    // Funzionale
    var acc = 0
    def accumulatore(x: Int) { acc += x }

    l.foreach(accumulatore)

    println(acc)

    println(sum)

    val o = l.foldLeft(0)((x, y) => x + y)

    println(o)

    val nomi = List("a", "b", "C")

    println(nomi.foldLeft("")((x: String, y: String) => x + y))


    println()
    // Calcolo del massimo mediante fold
    var numeri = List(5, 100, 3000, 60)
    def max(x: Int, y: Int) = (if (x > y) x else y)
    println(numeri.foldLeft(0)(max))

    
    println()
    // Lunghezza della stringa più lunga
    def strpl(x: Int, s: String) = if (s.length() > x) s.length() else x

    println(List("ciao", "tttttt").foldLeft(0)(strpl))

    var nn = List("a", "b", "c")
    
    
    println()
    // Si vuole stampare "a,b,c"
    print("Foreach: ")
    nn.foreach((x: String) => print(x + ","))
    println()

    println("FoldLeft: " + nn.foldLeft("")((x: String, y: String) => x + "," + y))
    println("FoldLeft: " + nn.foldLeft("")((x, y) => x + "," + y))
    println("ReduceLeft: " + nn.reduceLeft((x, y) => x + "," + y))

    
    println()
    println(List(3, 4, 5, 6).reduceLeft((x: Int, y: Int) => max(x, y)))
    println(l.reduceLeft((x, y) => if (x>y) x else y ))

  }

}