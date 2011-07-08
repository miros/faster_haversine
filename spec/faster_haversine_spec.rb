require 'spec_helper'

describe FasterHaversine do

  describe ".distance" do
    it "calculates distances" do
      first_point = [25.12345, 50.12345]

      expected_distances_to = {
        first_point => 0,
        [25, 50] => 18,
        [10, 10] => 4552,
        [85.321, 75.321] => 6747
      }

      expected_distances_to.each do |coords, distance|
        described_class.distance(*(first_point + coords)).should be_within(1).of(distance)
      end
    end
  end

  it "works as module method" do
    object = Object.new
    object.extend(described_class)
    object.send(:distance, 12, 34, 56, 78).should be_instance_of(Float)
  end

end
