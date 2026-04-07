defmodule Solution do
  def solve do
    # Считываем n
    input_n = IO.gets("") |> String.trim()

    if input_n != "" do
      n = String.to_integer(input_n)

      # Считываем числа и считаем квадраты
      kvad = Enum.reduce(1..n, 0, fn _, acc ->
        number = IO.gets("") |> String.trim() |> String.to_integer()

        # Проверка на полный квадрат
        num_sqrt = :math.sqrt(number) |> trunc()

        if num_sqrt * num_sqrt == number do
          acc + 1
        else
          acc
        end
      end)

      IO.puts("#{kvad}")
    end
  end
end

Solution.solve()
