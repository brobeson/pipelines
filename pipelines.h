#ifndef PIPELINES_CHANNEL_H
#define PIPELINES_CHANNEL_H

#include <functional>

namespace pipelines
{
  template <typename T>
  class channel
  {
  public:
    using value_type = T;
    void push(const value_type& value);
    [[nodiscard]] value_type pull();
    [[nodiscard]] empty() const noexcept;

  private:
    std::queue<value_type>
  };

  class pipe
  {
  public:
    /**
     * \brief Construct a new pipe object.
     * \tparam Input The type of data pulled from the input channel.
     * \tparam Output The type of data pushed to the output channel.
     * \tparam WorkFunction The function that will process in \a Input datum,
     * and produce one \a Output datum.
     * \param[in] input_channel The channel from which input data is pulled.
     * \param[in] output_channel The channel to which output is pushed.
     * \param[in] work_function The channel that processes the \a input to
     * produce an \a output. The signature must be
     * \code
     * Output work_function(Input&)
     * \endcode
     * The function input may be \a const.
     */
    template <typename Input, typename Output, typename WorkFunction>
    pipe(channel<Input>& input_channel,
         channel<Output>& output_channel,
         WorkFunction work_function);
  };

  class sink
  {
  public:
    template <typename Input>
    sink(channel<Input>& input_channel,
         std::function<void(Input)> sink_function);
  };
}  // namespace pipelines

#endif