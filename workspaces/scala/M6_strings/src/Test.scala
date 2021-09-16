object Test {
  
  def check(s: String): Boolean = {
    if (s.startsWith("a"))
      return true
    else
      return false
  }

  // For
  def pls_for(list: List[String]): Int = {
    var count = 0
    for(i <- list) {
      if(check(i))
        count += i.size
    }
    return count
  }

  // ForEach
  def pls_foreach(list: List[String]): Int = {
    var somma = 0
    list.foreach(s => if (s.startsWith("a")) (somma += s.size))
    return somma
  }

  // Recursion
  def pls_R(list: List[String]): Int = {
    if (list.isEmpty)
      return 0;

    if (list.head.startsWith("a"))
      return list.head.size + pls_R(list.tail)
    else
      return pls_R(list.tail);
  }

  // FoldLeft
  def pls_foldLeft(list: List[String]): Int = list.foldLeft(0)((x, y) => if (y.startsWith("a")) (x + y.size) else x)

  // Filter
  def pls_filter(list: List[String]): Int = {
    def loop(list: List[String]): Int = {
      if (list.isEmpty) 0
      else list.head.length + loop(list.tail)
    }

    loop(list.filter(_.startsWith("a")))
  }

  // Map
  def pls_map(list: List[String]): Int = list.filter(_.startsWith("a")).map(_.size).sum

  // HOF
  def pls(f: (String => Boolean)): List[String] => Int = {
    def inner(l: List[String]): Int = l.filter(f).map(_.size).sum
    inner
  }

  // Main
  def main(args: Array[String]) {
    val list = List("gino", "asino", "comodino", "aiuola")

    // Cerca le parole che iniziano con la lettera a
    // Poi somma la loro dimensione.
    // Esempio: asino = 5, aiuola = 6 > risultato = 11
    println("Pls (for): " + pls_for(list))
    println("Pls (foreach): " + pls_foreach(list))
    println("Pls (recursion): " + pls_R(list))
    println("Pls (foldLeft): " + pls_foldLeft(list))
    println("Pls (filter): " + pls_filter(list))
    println("Pls (map): " + pls_map(list))
    println("Pls (hof): " + pls(_.startsWith("a"))(list))
  }
}