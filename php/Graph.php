<?php
declare(strict_types=1);

class Edge
{
  public Vertex $start;
  public Vertex $end;
  public ?int $weight;

  public function __construct(Vertex $start, Vertex $end, ?int $weight)
  {
    $this->start = $start;
    $this->end = $end;
    $this->weight = $weight;
  }
}

class Vertex
{
  public string $data;
  public array $edges = [];

  public function __construct($data)
  {
    $this->data = $data;
  }

  public function equals(Vertex $other)
  {
    return $this->data === $other->data;
  }

  public function addEdge(Vertex $end, ?int $weight)
  {
    $edge = new Edge($this, $end, $weight);

    array_push($this->edges, $edge);
  }

  public function removeEdge(Vertex $end)
  {
    $this->edges = array_filter($this->edges, function (Edge $edge) use ($end) {
      return !$edge->end->equals($end);
    });
  }
}

class Graph
{
  public array $vertices = [];
  public bool $isWeighted;
  public bool $isDirected;

  public function __construct(bool $isWeighted, bool $isDirected)
  {
    $this->isWeighted = $isWeighted;
    $this->isDirected = $isDirected;
  }

  public function print()
  {
    foreach ($this->vertices as $vertex) {
      echo "{$vertex->data}\n";

      foreach ($vertex->edges as $edge) {
        if ($this->isWeighted) {
          echo "{$vertex->data} -> {$edge->end->data}: {$edge->weight}\n";
        } else {
          echo "{$vertex->data} -> {$edge->end->data}\n";
        }
      }
    }
  }

  public function printTraversal(array $arr, string $text)
  {
    echo "$text: ";

    foreach ($arr as $i => $val) {
      if ($i === 0) {
        echo "[$val, ";
      } else if ($i === count($arr) - 1) {
        echo "$val]\n";
      } else {
        echo "$val, ";
      }
    }
  }

  public function addVertex(String $data): Vertex
  {
    $vertex = new Vertex($data);

    array_push($this->vertices, $vertex);

    return $vertex;
  }

  public function removeVertex(Vertex $vertex)
  {
    $this->vertices = array_filter($this->vertices, function (Vertex $v) use ($vertex) {
      return !$v->equals($vertex);
    });
  }

  public function addEdge(Vertex $v1, Vertex $v2, ?int $weight)
  {
    if (!$this->isWeighted) {
      $weight = null;
    }

    $v1->addEdge($v2, $weight);

    if (!$this->isDirected) {
      $v2->addEdge($v1, $weight);
    }
  }

  public function removeEdge(Vertex $v1, Vertex $v2)
  {
    $v1->removeEdge($v2);

    if (!$this->isDirected) {
      $v2->removeEdge($v1);
    }
  }

  public function dfs(Vertex $start, array &$visited, array &$arr)
  {
    array_push($visited, $start);
    array_push($arr, $start->data);

    foreach ($start->edges as $edge) {
      $neighbor = $edge->end;

      if (array_search($neighbor, $visited, true) === false) {
        $this->dfs($neighbor, $visited, $arr);
      }
    }
  }

  public function bfs(Vertex $start, array &$arr)
  {
    $visited = [$start];
    $queue = [$start];

    while (count($queue) > 0) {
      $vertex = array_shift($queue);

      array_push($arr, $vertex->data);

      foreach ($vertex->edges as $edge) {
        $neighbor = $edge->end;

        if (array_search($neighbor, $visited, true) === false) {
          array_push($visited, $neighbor);
          array_push($queue, $neighbor);
        }
      }
    }
  }
}

$graph = new Graph(false, false);

$v0 = $graph->addVertex("0");
$v1 = $graph->addVertex("1");
$v2 = $graph->addVertex("2");
$v3 = $graph->addVertex("3");
$v4 = $graph->addVertex("4");

$graph->addEdge($v0, $v1, null);
$graph->addEdge($v0, $v2, null);
$graph->addEdge($v1, $v2, null);
$graph->addEdge($v1, $v3, null);
$graph->addEdge($v2, $v4, null);
$graph->addEdge($v3, $v4, null);

echo "Unweighted and Undirected Graph\n";

$graph->print();

$graph = new Graph(true, false);

$v0 = $graph->addVertex("0");
$v1 = $graph->addVertex("1");
$v2 = $graph->addVertex("2");
$v3 = $graph->addVertex("3");
$v4 = $graph->addVertex("4");

$w01 = 10;
$w02 = 10;
$w12 = 5;
$w13 = 15;
$w24 = 15;
$w34 = 5;

$graph->addEdge($v0, $v1, $w01);
$graph->addEdge($v0, $v2, $w02);
$graph->addEdge($v1, $v2, $w12);
$graph->addEdge($v1, $v3, $w13);
$graph->addEdge($v2, $v4, $w24);
$graph->addEdge($v3, $v4, $w34);

echo "\n\nWeighted and Undirected Graph\n";

$graph->print();

$graph = new Graph(true, true);

$v0 = $graph->addVertex("0");
$v1 = $graph->addVertex("1");
$v2 = $graph->addVertex("2");
$v3 = $graph->addVertex("3");
$v4 = $graph->addVertex("4");

$graph->addEdge($v0, $v1, $w01);
$graph->addEdge($v0, $v2, $w02);
$graph->addEdge($v1, $v2, $w12);
$graph->addEdge($v1, $v3, $w13);
$graph->addEdge($v2, $v4, $w24);
$graph->addEdge($v3, $v4, $w34);

echo "\n\nWeighted and Directed Graph\n";

$graph->print();

echo PHP_EOL;

$visited = [];
$arr = [];

$graph->dfs($v0, $visited, $arr);

$graph->printTraversal($arr, "dfs traversal");

$arr = [];

$graph->bfs($v0, $arr);

$graph->printTraversal($arr, "bfs traversal");