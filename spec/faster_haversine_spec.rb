require 'spec_helper'

describe FasterHaversine do

  describe ".distance" do
    it "works" do
      ap described_class.distance(20, 50, 20.12345, 50.12345)
    end
  end

  it "works as module method" do
    object = Object.new
    object.extend(described_class)
    ap object.send(:distance, 20, 50, 20.12345, 50.12345)
  end

end
