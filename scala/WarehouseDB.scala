class WarehouseDB extends StockControl {

  // items currently stocked in warehouse
  private var stockedItems = Array[Item]()

  def add(i: Item): Array[Item] = {
    if(stockedItems.exists(x => x.id == i.id))
      println("Error: item with id " + i.id + " already exists in stock. => "
        + i.name + " not added.")
    else{
      stockedItems = stockedItems :+ i   // append new item to array
      i.log(i.name, "was added correctly.")
    }
    stockedItems
  }

  def delete(id: Int): Array[Item] = {
    // search item with same ID (type is Option: it could be found or not)
    val removeItem: Option[Item] = stockedItems.find(x => x.id == id)

    // if item is found then log a "delete message" else print error
    removeItem match {
      case None => println("Error: item with id " + id + " was not found.")
      case Some(found) => found.log(found.name, "was deleted.")
    }

    // new array without the deleted item
    stockedItems = stockedItems.filter(x => x.id != id)
    stockedItems
  }

  def mean_fold(): Int = stockedItems.foldLeft(0)((x,y) => x + y.price)/stockedItems.length

  def mean_for(): Int = {
    var sum = 0
    for (x <- stockedItems)
      sum += x.price
    sum/stockedItems.length
  }

  def modifyPrice(id: Int, price: Int): Array[Item] = {
    println("Changing price to item " + id + "...")
    val newPrice: Option[Item] = stockedItems.find(x => x.id == id)

    newPrice match {
      case None => println("Error: item with id " + id + " was not found. Cannot change price.")
      case Some(found) =>
        println("Old price: " + found.price)
        found.price = price
        println("New price: " + found.price)
    }

    println("Price for item " + id + " changed correctly.")
    stockedItems
  }

  def print(): Unit = {
    println("Stock availability (ID - Name - Price)")
    stockedItems.foreach(i => println(i.id + " - " + i.name + " - " + i.price))
  }

  def search(name: String): Array[Item] = {
    // array of all items with the same name
    val searchList = stockedItems.filter(x => x.name == name)
    println("Number of available items with name " + name + ": " + searchList.length)

    if(searchList.isEmpty)
      println("Error: item '" + name + "' is not available in stock.")

    searchList.foreach(x => x.log(x.name, "id " + x.id + " is available in stock."))
    searchList
  }

  def sum(): Int = stockedItems.map(x => x.price).reduce((a,b) => a + b)

  /*
  def sum(): Int = {
    // array of prices from stored items > then sum all prices
    val allPrices = stockedItems.map(x => x.price).reduce((a,b) => a + b)
    // alternative method: allPrices.sum
    allPrices
  }
  */
}