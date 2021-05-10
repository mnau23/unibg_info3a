/*
==========================================================================================
Name        : SWM: ScalaWarehouseManager
Author      : Emanuele Perico
Version     : 1.0
Description : The scenario chosen for this project is that of managing a warehouse:
              making use of traits and various operations on collections,
              it is shown a small example of managing goods in stock.
==========================================================================================
*/

object Main  {

  def main(args: Array[String]) {
    val db = new WarehouseDB()
    val item1 = new Item(1, "article1", 600)
    val item2 = new Item(2, "article2", 900)
    val item3 = new Item(1, "article3", 50)
    val item4 = new Item(4, "article4", 100)
    val item5 = new Item(5, "article5", 70)
    val item6 = new Item(6, "article", 1200)
    val item7 = new Item(7, "article", 1400)

    println

    db.add(item1)
    println("----------------------------------------------")
    db.print()
    println("Sum of the items' prices in stock: " + db.sum())
    println("----------------------------------------------")

    db.add(item2)
    db.add(item3)
    db.add(item4)
    db.add(item5)
    db.add(item6)
    db.add(item7)
    println("----------------------------------------------")
    db.print()
    println("Sum of the items' prices in stock: " + db.sum())
    println("----------------------------------------------")

    db.delete(5)
    println("----------------------------------------------")
    db.print()
    println("Sum of the items' prices in stock: " + db.sum())
    println("----------------------------------------------")

    db.search("article")
    println("----------------------------------------------")

    db.modifyPrice(2, 800)
    println("----------------------------------------------")
    db.print()
    println("Sum of the items' prices in stock: " + db.sum())
    println("----------------------------------------------")

    println("Average price (using fold): " + db.mean_fold())
    println("Average price (using for): " + db.mean_for())
    println("----------------------------------------------")
  }

}