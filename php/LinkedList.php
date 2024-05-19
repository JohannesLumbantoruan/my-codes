<?php
declare(strict_types=1);

class Node
{
  public int $data;
  public ?Node $next;

  public function __construct(int $data)
  {
    $this->data = $data;
    $this->next = null;
  }
}

class LinkedList
{
  public ?Node $head;
  public int $length = 0;

  public function __construct()
  {
    $this->head = null;
  }

  public function print(): string
  {
    $node = $this->head;

    if ($node === null) {
      return "null";
    }

    $result = [];

    while ($node !== null) {
      array_push($result, $node->data);
      $node = $node->next;
    }

    array_push($result, "null");

    return join("->", $result);
  }

  public function unshift(int $data)
  {
    $node = new Node($data);

    if ($this->head === null) {
      $this->head = $node;
    } else {
      $node->next = $this->head;
      $this->head = $node;
    }

    $this->length += 1;
  }

  public function push(int $data)
  {
    $node = new Node($data);

    if ($this->head === null) {
      $this->head = $node;
    } else {
      $current = $this->head;

      while ($current !== null) {
        if ($current->next === null) {
          $current->next = $node;
          break;
        } else {
          $current = $current->next;
        }
      }
    }

    $this->length += 1;
  }

  public function shift()
  {
    $node = $this->head;

    if ($node === null) {
      throw new Exception("ZeroLengthException: Linked List length is zero");
    } else {
      $this->head = $node->next;
    }

    $this->length -= 1;
  }

  public function pop()
  {
    $node = $this->head;

    if ($node === null) {
      throw new Exception("ZeroLengthException: Linked List length is zero");
    } else {
      $prev = $node;

      while ($node !== null) {
        if ($node->next === null) {
          $prev->next = null;
          break;
        } else {
          $prev = $node;
          $node = $node->next;
        }
      }
    }

    $this->length -= 1;
  }
}

$ll = new LinkedList();

for ($i = 1; $i <= 5; $i++) {
  $ll->unshift($i * 10);
}

echo $ll->print() . ", length: {$ll->length}\n";

for ($i = 1; $i <= 5; $i++) {
  $ll->push($i * 5);
}

echo $ll->print() . ", length: {$ll->length}\n";

$ll->shift();

echo $ll->print() . ", length: {$ll->length}\n";

$ll->pop();

echo $ll->print() . ", length: {$ll->length}\n";